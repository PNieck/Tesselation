#include <tesselation/window.hpp>
#include <tesselation/controllers/mainController.hpp>


int main()
{
    Window window(600, 400, "Tesselation");

    window.RunMessageLoop();

    return 0;
}
