#ifndef SDL2_THROWERRORS_H
#define SDL2_THROWERRORS_H

/*!
 * Includes all exceptions that can be thrown
 */
namespace error {
    class CannotCreateWindowException {};
    class WindowDoesNotExistException {};
    class CannotInitSDLException {};
    class CannotCreateRendererException {};
    class RendererDoesNotExistException {};
    class RenderDrawLineException {};
    class SetRenderDrawColorException {};
    class RenderClearException {};
    class UnsupportedMethodException {};
    class FileReadException {};
    class FileOpenException {};
    class CharacterDoesNotExistException {};
    class UpgradeDoesNotExistException {};
}

#endif //SDL2_THROWERRORS_H
