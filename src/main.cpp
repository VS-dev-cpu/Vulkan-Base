#include <objio.hpp>
#include <vk.hpp>

int main() {
    srand(time(0));

    mesh_t mesh;
    mesh_load(&mesh, "../res/polyplanet.obj");

    VulkanBase app(Model::load(mesh), "Vulkan Base");
    try {
        float now = time(), then = now;

        while (app.update()) {
            then = now;
            now = time();
            float deltaTime = now - then;
        }

    } catch (const std::exception &e) {
        printf("%s\n", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}