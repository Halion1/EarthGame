#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>

map<char, sf::Color> colores = {
        {'R',sf::Color::Red},
        {'G',sf::Color::Green},
        {'B',sf::Color::Blue},
};

using namespace std;

Tierra::Tierra() {
    plano = nullptr;
//    plano.resize(ALTURA);
//    for (auto& item: plano)
//        item.resize(ANCHO);
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) {
    plano = new sf::RenderWindow(
            sf::VideoMode(ancho,altura), "Proyecto Final");
//    plano.resize(altura);
//    for (auto& item: plano)
//        item.resize(ancho);
}

Tierra::~Tierra() {
    delete plano;
    plano = nullptr;
}

void Tierra::adicionarObjeto(Objeto* objeto) {
    objetos.emplace_back(objeto);
}

Objeto* Tierra::removerObjeto(string& nombre) {
    // Si vector esta vacio
    if (objetos.size() == 0)
        return nullptr;
    // Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto *obj) { return obj->getNombre() == nombre; });
    if (iter != end(objetos)) {
        // Eliminando la referencia al puntero objeto dentro del vector objetos
        objetos.erase(iter);
        //-- si encuentra al objeto lo separa del vector,
        //-- (no libera de memoria el objeto encontrado), esto se hará en el menú,
        //-- donde fue asignado, debido a que el objeto no es parte sino el objeto es un visitante.
        return *iter;

        // Si vector esta vacio
        return nullptr;
    }
}
    void Tierra::imprimirObjetos() {
        int i = 0;
        for (auto &item: objetos) {
            cout << "* * * * * * [" << i << "] ";
            cout << " Nombre = " << item->getNombre() << " "
                 << item->mostrarPosicion()
                 << " Color = " << item->getColor() << '\n';
            i++;

        }
    }
void Tierra::actualizarTierra() {
    for (auto &row: plano){
        sd::CircleShape shape(10);
        shape.setFillColor(colores[item->getColor()]);
        shape.setPosition(item->getPosX(), item->getPosY());
        plano->draw(shape);
    }
//        for (auto &cell: row)
//            cell = COLOR;
//
//    for (auto& item: objetos)
//        plano[item->getPosX()][item->getPosY()]
//                = item->getColor();
}

void Tierra::dibujarTierra() {
    if (plano== nullptr)return;
    while (plano.isOpen())
      {
        sf::Event event;
      while (plano->pollEvent(event))
       {
         if (event.type == sf::Event::Closed)
            plano->lose();
    }

      plano->clear();
      plano->draw(shape);
      plano->display();
     }
}

TipoEntero Tierra::getAltura() {
    return -> getPosition().y;
}

TipoEntero Tierra::getAncho(){
    return -> getPosition().x;
}

