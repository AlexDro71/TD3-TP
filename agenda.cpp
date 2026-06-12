#include "agenda.h"
#include <algorithm>

Agenda::Agenda(){ 
    _cantReservas=0; 
}

const list<Reserva>& Agenda::reservas() const {
    return _reservas;
}

void Agenda::registrar_reserva(Reserva r) {
    _cantReservas++;
    _reservas.push_back(r);
    _reservas_por_dia[principio_del_dia(r.fecha_hora)]++; // O (log D)
}

int Agenda::cantidad_reservas() const {
    return _cantReservas;
}

vector<Reserva> Agenda::ultimas_reservas(int k) const {
    // Implementación trivial O(n): recorre toda la lista
    vector<Reserva> resultado;
    const list<Reserva>& todas = _reservas;
    auto it = todas.rbegin();
    if(_cantReservas < k) k=_cantReservas;
    for(int i=0; i<k; i++){
        resultado.push_back(*it);
        ++it;
    }

    return resultado;
}

int Agenda::reservas_del_dia(timestamp t) const {
    // Implementación trivial O(n): recorre toda la lista
    timestamp inicio_dia = principio_del_dia(t);
    auto it = _reservas_por_dia.find(inicio_dia); //find busca directo al dia buscado
    if (it == _reservas_por_dia.end()) // si el dia no tiene reservas
        return 0;
    
        return it->second; // la cantidad de reservas de ese dia 
    
    
}

vector<string> Agenda::clientes_frecuentes(int k) const {
   vector<string> resultado;
    auto it = frecuentes.rbegin();
    for(int i =0; i< k && it != ranking.end() ; i++ , ++it){
        resultado.pushback(it->second); //el nombre del cliente
    }
    return resultado;
}
    
