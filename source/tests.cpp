#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <numbers>
#include <cmath>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


TEST_CASE("Spheres and Boxes", "[Task 5.2]")
{
  SECTION("Sphere Constructors")
  {
    Sphere sphere1{};

    REQUIRE(sphere1.get_center_test().x == Approx(0.0f));
    REQUIRE(sphere1.get_center_test().y == Approx(0.0f));
    REQUIRE(sphere1.get_center_test().z == Approx(0.0f));
    REQUIRE(sphere1.get_radius_test() == Approx(1.0f));


    Sphere sphere2{ glm::vec3{-4.5f, 1.4f, 10.0f}};

    REQUIRE(sphere2.get_center_test().x == Approx(-4.5f));
    REQUIRE(sphere2.get_center_test().y == Approx(1.4f));
    REQUIRE(sphere2.get_center_test().z == Approx(10.0f));
    REQUIRE(sphere2.get_radius_test() == Approx(1.0f));


    Sphere sphere3{ glm::vec3{-4.5f, 1.4f, 10.0f}, -7.8f };

    REQUIRE(sphere3.get_center_test().x == Approx(-4.5f));
    REQUIRE(sphere3.get_center_test().y == Approx(1.4f));
    REQUIRE(sphere3.get_center_test().z == Approx(10.0f));
    REQUIRE(sphere3.get_radius_test() == Approx(7.8f));
  }
  SECTION("Box")
  {
    Box box1{};

    REQUIRE(box1.get_min_test().x == Approx(0.0f));
    REQUIRE(box1.get_min_test().y == Approx(0.0f));
    REQUIRE(box1.get_min_test().z == Approx(0.0f));

    REQUIRE(box1.get_max_test().x == Approx(1.0f));
    REQUIRE(box1.get_max_test().y == Approx(1.0f));
    REQUIRE(box1.get_max_test().z == Approx(1.0f));


    Box box2{ glm::vec3{12.6f, -0.9f, 129.05f}, glm::vec3{5.5f, -4.4f, 3.3f} };

    REQUIRE(box2.get_min_test().x == Approx(12.6f));
    REQUIRE(box2.get_min_test().y == Approx(-0.9f));
    REQUIRE(box2.get_min_test().z == Approx(129.05f));

    REQUIRE(box2.get_max_test().x == Approx(5.5f));
    REQUIRE(box2.get_max_test().y == Approx(-4.4f));
    REQUIRE(box2.get_max_test().z == Approx(3.3f));
  }
}