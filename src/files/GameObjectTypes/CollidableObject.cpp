#include "CollidableObject.h"

CollidableObject::CollidableObject(const DVector2D &_spawnPosition, const Rotation &_spawnRotation)
        : GraphicsObject(_spawnPosition, _spawnRotation) {
}

void CollidableObject::SetPointVector(const std::vector<DVector2D> &_newPoints, bool _isClosedLoop) {
    GraphicsObject::SetPointVector(_newPoints, _isClosedLoop);  // Create the graphics
    collision_radius = CalcCollisionRadius();                   // Calculate the collision radius
}

void CollidableObject::RescaleGraphics(const double &_rescaleFactor) {
    GraphicsObject::RescaleGraphics(_rescaleFactor);
    collision_radius = CalcCollisionRadius();
}

void CollidableObject::CheckSideCollisions() {
    // The lambda functions for boundary checking
    auto topCheck = [](const DVector2D & point) { return (point.y < 0); };
    auto topAdd = [](DVector2D & point) { point.y += (double)settings::SCREEN_HEIGHT; };
    auto leftCheck = [](const DVector2D & point) { return (point.x < 0); };
    auto leftAdd = [](DVector2D & point) { point.x += (double)settings::SCREEN_WIDTH; };
    auto botCheck = [](const DVector2D & point) { return (point.y > (double)settings::SCREEN_HEIGHT); };
    auto botAdd = [](DVector2D & point) { point.y -= (double)settings::SCREEN_HEIGHT; };
    auto rightCheck = [](const DVector2D & point) { return (point.x > (double)settings::SCREEN_WIDTH); };
    auto rightAdd = [](DVector2D & point) { point.x -= (double)settings::SCREEN_WIDTH; };

    // Top boundary check
    if(position.y - collision_radius < 0) {
        CheckBoundarySide(topCheck, topAdd, SuperManager().Instance()->renderManager);
    }

    // Left boundary check
    if(position.x - collision_radius < 0) {
        CheckBoundarySide(leftCheck, leftAdd, SuperManager().Instance()->renderManager);
    }

    // Bottom boundary check
    if (position.y + collision_radius > settings::SCREEN_HEIGHT) {
        CheckBoundarySide(botCheck, botAdd, SuperManager().Instance()->renderManager);
    }

    // Right boundary check
    if (position.x + collision_radius > settings::SCREEN_WIDTH) {
        CheckBoundarySide(rightCheck, rightAdd, SuperManager().Instance()->renderManager);
    }
}

bool CollidableObject::Collision(const GameObject *other) const {
    // check if they are in radius (check their distance and comp with collision radius)
    if ((other->position - position).Length() < (other->GetCollisionRadius() + this->GetCollisionRadius())) {
        // Get the sizes of vectors
        size_t this_vector_size = this->GetPointVector().size();
        size_t other_vector_size = other->GetPointVector().size();

        // Draw lines between all points in rectangle in this CollidableObject
        for (size_t i = 0; i < this_vector_size; i++) {
            // Calculate THIS line
            DLine this_line(0, 0);
            if (i != this_vector_size - 1) {
                this_line.p1 = this->GetPointVector()[i];
                this_line.p2 = this->GetPointVector()[i + 1];
            }
            else if (this->IsClosedLoop()) {
                this_line.p1 = this->GetPointVector()[i];
                this_line.p2 = this->GetPointVector()[0];
            }

            for (size_t y = 0; y < other_vector_size; y++) {
                // Calculate OTHER line
                DLine other_line(0, 0);
                if (y != other_vector_size - 1) {
                    other_line.p1 = other->GetPointVector()[y];
                    other_line.p2 = other->GetPointVector()[y + 1];
                }
                else if (other->IsClosedLoop()) {
                    other_line.p1 = other->GetPointVector()[y];
                    other_line.p2 = other->GetPointVector()[0];
                }

                // Get the real world coordinates
                this_line.p1 = this->GetRealCoordinates(this_line.p1);
                this_line.p2 = this->GetRealCoordinates(this_line.p2);
                other_line.p1 = other->GetRealCoordinates(other_line.p1);
                other_line.p2 = other->GetRealCoordinates(other_line.p2);

                // If there was an intersection return true
                if (this_line.Intersection(other_line)) {
                    return true;
                }
            }
        }
    }

    // No intersection found
    return false;
}

double CollidableObject::CalcCollisionRadius() const {
    double max = 0;                                             // Set the max distance to 0
    for (size_t i = 0; i < GetPointVector().size(); i++) {
        double curLen = GetPointVector()[i].Length();           // Compute the distance for each point
        if(curLen > max) {
            max = curLen;                                       // Assign the distance if it is bigger than the max
        }
    }
    return max;
}

template<typename _T, typename _K>
void CollidableObject::CheckBoundarySide(_T check, _K add, RenderManager &_lineRenderer) {
    bool stillInside = false;                                   // If the ship has not fully crossed the border
    bool drawn = false;                                         // If the duplicate was not drawn yet

    // Check each point of PointVector if it is not outside of the game screen
    for (size_t i = 0; i < GetPointVector().size(); i++) {
        if (check(GetRealCoordinates(GetPointVector()[i]))) {
            if (!drawn) {                                       // Draw the ghost GameObject only once
                drawn = true;                                   // Set the drawn flag
                DVector2D prev = this->position;                // Save the previous position
                add(position);                                  // Set the shift
                DrawGraphics(this, _lineRenderer);              // Draw this same ship on the other side
                position = prev;                                // Recover the previous position
            }
        }
        else {
            stillInside = true;                                 // One of the points is still on the original screen side
        }
    }

    if (!stillInside) {
        add(position);                                          // Push the real position over the edge
    }
}

double CollidableObject::GetCollisionRadius() const {
    return collision_radius;
}
