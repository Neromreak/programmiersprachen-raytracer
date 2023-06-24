#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <numbers>
#include <cmath>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "hit_point.hpp"

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


    Sphere sphere2{ glm::vec3{-4.5f, 1.4f, 10.0f} };

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
  SECTION("Box Constructors")
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

  SECTION("Sphere area and volume")
  {
    Sphere sphere1{};

    REQUIRE(sphere1.area() == Approx(12.566).margin(0.001f));
    REQUIRE(sphere1.volume() == Approx(4.189).margin(0.001f));


    Sphere sphere2{ glm::vec3{-4.5f, 1.4f, 10.0f}, 3.3f };

    REQUIRE(sphere2.area() == Approx(136.848).margin(0.001f));
    REQUIRE(sphere2.volume() == Approx(150.533).margin(0.001f));

    // Sources for tests:
    // https://www.matheretter.de/rechner/kugel
  }
  SECTION("Box area and volume")
  {
    Box box1{};

    REQUIRE(box1.area() == Approx(6.0f).margin(0.001f));
    REQUIRE(box1.volume() == Approx(1.0f).margin(0.001f));


    Box box2{ glm::vec3{-4.5f, 1.4f, 10.0f}, glm::vec3{2.5f, 5.4f, -10.0f} };

    REQUIRE(box2.area() == Approx(496).margin(0.001f));
    REQUIRE(box2.volume() == Approx(560).margin(0.001f));

    // Sources for tests:
    // https://www.matheretter.de/rechner/kugel
  }
}

TEST_CASE("Name and Color", "[Task 5.3]")
{
  Sphere sphere1{};

  REQUIRE(sphere1.get_name() == "Shape");
  REQUIRE(sphere1.get_color().r == 0.0f);
  REQUIRE(sphere1.get_center_test() == glm::vec3{0.0f, 0.0f, 0.0f});
  REQUIRE(sphere1.get_radius_test() == 1.0f);

  Box box1{ {2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f}, "boxy box", {8.0f, 9.0f, 10.0f} };

  REQUIRE(box1.get_name() == "boxy box");
  REQUIRE(box1.get_color().r == 8.0f);
  REQUIRE(box1.get_min_test() == glm::vec3{ 2.0f, 3.0f, 4.0f });
  REQUIRE(box1.get_max_test() == glm::vec3{5.0f, 6.0f, 7.0f});
}

TEST_CASE("Output of Names of Shapes", "[Task 5.5]")
{
  std::cout << "Task 5.5:\n";

  Sphere sphere1{};
  std::cout << "sphere1: " << sphere1 << "\n";

  Box box1{ {"hotdog"}, {0.01f, 0.02f, 0.03f} };
  std::cout << "box1: " << box1 << "\n";
}
// Schlüsselwort override:
// -überschreibt die Methode der Basisklasse nicht. Dass passiert automatisch, wenn
// Methode in Basisklasse als virtual geflaggt ist und die Signaturen übereinstimmen.
// -überprüft stattdessen nur ob eine entsprechende virtual Methode zum 
// überschreiben existiert und gibt einen Fehler aus, sollte dem nicht so sein. 
// -Fängt somit Fehler ab, die schwer zu finden wären
//

TEST_CASE("Intersect_ray_sphere", "[Task 5.6]")
{
  SECTION("glm_intersect")
  {
    // Ray
    glm::vec3 ray_origin{ 0.0f , 0.0f , 0.0f };
    glm::vec3 ray_direction{ 0.0f , 0.0f , 1.0f };
    // Sphere
    glm::vec3 sphere_center{ 0.0f ,0.0f , 5.0f };
    float sphere_radius{ 1.0f };
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(ray_origin, ray_direction, sphere_center,
      sphere_radius * sphere_radius, distance);
    REQUIRE(distance == Approx(4.0f));
  }
  SECTION("own_Intersect")
  {
    Sphere sphere1{};
    Ray ray1{};

    HitPoint hit_point1 = sphere1.intersect(ray1);
    REQUIRE(hit_point1.hit_ == true);
    REQUIRE(hit_point1.distance_ == Approx(1.0f));
    REQUIRE(hit_point1.pos_.x == Approx(0.0f));
    REQUIRE(hit_point1.pos_.y == Approx(0.0f));
    REQUIRE(hit_point1.pos_.z == Approx(-1.0f));
    REQUIRE(hit_point1.direction_.x == Approx(0.0f));
    REQUIRE(hit_point1.direction_.y == Approx(0.0f));
    REQUIRE(hit_point1.direction_.z == Approx(-1.0f));
    REQUIRE(hit_point1.hit_obj_name_ == "Shape");
    REQUIRE(hit_point1.hit_obj_color_.r == Approx(0.0f));
    REQUIRE(hit_point1.hit_obj_color_.g == Approx(0.0f));
    REQUIRE(hit_point1.hit_obj_color_.b == Approx(0.0f));
    
    Sphere sphere2{ {5.0f, 3.0f, 10.0f}, 2.0f, "Herbert", {0.8f, 0.7f, 0.6f} };
    Ray ray2{ {7.0f, 4.0f, -1.0f}, {-2.0f, -1.0f, 9.0f} };

    HitPoint hit_point2 = sphere2.intersect(ray2);
    REQUIRE(hit_point2.hit_ == true);
    REQUIRE(hit_point2.distance_ == Approx(9.27362f).margin(0.001f));
    REQUIRE(hit_point2.pos_.x == Approx(5.0f));
    REQUIRE(hit_point2.pos_.y == Approx(3.0f));
    REQUIRE(hit_point2.pos_.z == Approx(8.0f));
    REQUIRE(hit_point2.direction_.x == Approx(-0.21567f).margin(0.001f));
    REQUIRE(hit_point2.direction_.y == Approx(-0.10783f).margin(0.001f));
    REQUIRE(hit_point2.direction_.z == Approx(0.97049f).margin(0.001f));
    REQUIRE(hit_point2.hit_obj_name_ == "Herbert");
    REQUIRE(hit_point2.hit_obj_color_.r == Approx(0.8f));
    REQUIRE(hit_point2.hit_obj_color_.g == Approx(0.7f));
    REQUIRE(hit_point2.hit_obj_color_.b == Approx(0.6f));

    Sphere sphere3{ {10.0f, 0.0f, 0.0f}, 5.0f, "Gregorius", {0.1f, 0.2f, 0.3f} };
    Ray ray3{ {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f} };
    Ray ray4{ {0.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f} };
    Ray ray5{ {0.0f, 5.0f, 0.0f}, {1.0f, 0.0f, 0.0f} };

    HitPoint hit_point3 = sphere3.intersect(ray3);
    HitPoint hit_point4 = sphere3.intersect(ray4);
    HitPoint hit_point5 = sphere3.intersect(ray5);
    REQUIRE(hit_point3.hit_ == true);
    REQUIRE(hit_point4.hit_ == false);
    REQUIRE(hit_point5.hit_ == true);
  }
}

TEST_CASE("Static_And_Dynamic_Types", "[Task 5.7]")
{
  std::cout << "\nTask 5.7:\n";

  Color red{ 1.0f, 0.0f, 0.0f};
  glm::vec3 position{ 0.0f, 0.0f, 0.0f };
  std::shared_ptr<Sphere> s1 = std::make_shared <Sphere>(position, 1.2f, "sphere0", red);
  std::shared_ptr<Shape>  s2 = std::make_shared <Sphere>(position, 1.2f, "sphere1", red);

  s1->print(std::cout);
  std::cout << "\n";
  s2->print(std::cout);
  std::cout << "\n";
}
// (Task 5.7) static/dynamic types
// Statischer Typ einer Variable:
// -bezeichnet den Typen der Variable welcher zur Deklarierung der Variable festgelegt wurde.
// Der statische Typ wird zur Übersetzungszeit gebunden und kann sich dann nicht mehr ändern.
// 
// Dynamischer Typ einer Variable:
// -bezeichnet den Typen der Variable welcher gerade von dieser referenziert wird.
// Der dynamische Typ wird erst zur Laufzeit des Programms festgelegt und kann demnach auch
// noch während der Laufzeit geändert werden.
// 
// Wann wird welcher Typ überprüft:
// Greift man auf eine Methode einer Variable zu, so wird schon bei Übersetzung geprüft, ob
// der statische Typ der Variable diese Methode überhaupt definiert und entsprechend
// potentiell eine Fehlermeldung ausgegeben wenn diese Methode nicht definiert ist. Auf die
// eigentliche Definition der Methode wird jedoch erst bei Laufzeit zugegriffen. Somit ist
// dabei der dynamische Typ der Variable relevant, da über diesen die Implementierung der
// Methode gewählt wird.
// 
// S1 statisch:   Sphere
// S1 dynamisch:  Sphere
// S2 statisch:   Shape
// S2 dynamisch:  Sphere
//

TEST_CASE("Virtual_Destructor", "[Task 5.8]")
{
  std::cout << "\nTask 5.8:\n";

  Color red{ 1.0f, 0.0f, 0.0f };
  glm::vec3 position{ 0.0f, 0.0f, 0.0f };
  Sphere* s1 = new Sphere{ position , 1.2f , "sphere0", red };
  Shape*  s2 = new Sphere{ position , 1.2f , "sphere1", red };

  s1->print(std::cout);
  std::cout << "\n";
  s2->print(std::cout);
  std::cout << "\n";

  delete s1;
  delete s2;

  // with virtual destructor:
  // Shape constructor    // Erst Konstruktor der Basisklasse
  // Sphere constructor   // Dann Konstruktor der abgleiteten Klasse
  // Shape constructor
  // Sphere constructor
  // 
  // Sphere destructor    // Erst Destruktor der abgeleiteten Klasse
  // Shape destructor     // Dann Destruktor der Basisklasse
  // Sphere destructor
  // Shape destructor

  // with non virtual destructor:
  // Shape constructor
  // Sphere constructor
  // Shape constructor
  // Sphere constructor
  // 
  // Sphere destructor    // s1 wird normal deleted           (statisch Sphere | dynamisch Sphere)
  // Shape destructor
  // Shape destructor     // s2 wird nur Basisklasse deleted  (statisch Shape | dynamisch Sphere)
 }

// (Task 5.9) Klassenhierachchie u.ä.
// Klassenhierarchie:
// -beschreibt die Konstellation und Beziehungen zwischen mehreren Klassen wie 
// Basisklasse und devon abgeleitete Klassen
// 
// Objekthierarchie:
// -beschreibt die Konstellation und Beziehung der tatsächlich existierenden Instanzen
// der Klassen
// 
// Klassendiagramm/Objektdiagramm:
// Darstellung der Hierarchien als Diagramm
//