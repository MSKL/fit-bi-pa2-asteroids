#ifndef SDL2_GRAPHICOBJECT_H
#define SDL2_GRAPHICOBJECT_H

#include <cmath>
#include <vector>
#include "GameObject.h"
#include "../Utility/Color.h"
#include "../Managers/SuperManager.h"

/*!
 * GameObject that countains a vector rectangle
 */
class GraphicsObject : public GameObject {
public:
    /*!
     * The default constructor of GraphicsObject
     * @param _spawnPosition spawn position
     * @param _spawnRotation spawn rotation
     */
    GraphicsObject(const DVector2D & _spawnPosition, const Rotation & _spawnRotation);

    /*!
     * Draw this GraphicObject
     */
    virtual void Draw() override;

    /*!
     * Check if the rectangle us closed
     * @return true if rectangle is closed
     */
    virtual bool IsClosedLoop() const override;

    /*!
     * Get the vector of points that make a rectangle
     * @return vector of points from rectangle
     */
    virtual std::vector<DVector2D> GetPointVector() const override;

    /*!
     * Assign the points into the rectangle. Clear the previous ones.
     * @param _newPoints new points
     * @param _isClosedLoop true if the rectangle is closed
     */
    virtual void SetPointVector(const std::vector<DVector2D> & _newPoints, bool _isClosedLoop = true);

    /*!
     * Rescale all points in the vector of points
     * @param _rescaleFactor factor to multiple all vectors by
     */
    virtual void RescaleGraphics(const double & _rescaleFactor);

protected:
    /*!
     * Draw all points from PointsVector
     * @param target GraphicsObject to be drawn
     * @param _lineRenderer renderer to draw the graphics
     */
    void DrawGraphics(const GraphicsObject* target, RenderManager & _lineRenderer);

    /*!
     * Transforms the local coordinates to the global based on the rotation and base position
     * @param _localCoord local coordinates
     * @return global coordinates
     */
    virtual DVector2D GetRealCoordinates (const DVector2D & _localCoord) const override;

private:
    bool closed_loop;                       // Rectangle is a closed loop by default
    std::vector<DVector2D> pointVector;     // Vector of points ov the rectangle
};

#endif //SDL2_GRAPHICOBJECT_H
