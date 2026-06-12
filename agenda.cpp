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
    string cliente = r.cliente; //el nombre del cliente de la reserva 

    auto it = _reservas_por_cliente.find(cliente); //O(log C) quiero saber si el cliente ya tenia reserva
    if (it != _reservas_por_cliente.end()){
        int cantidad_antes = it->second // cantidad de reservas de ese cliente de antes
        _ranking.erase({cantidad_antes, cliente}); // lo borro del ranking para cambiarlo de posicion
        it->second =  cantidad_antes +1; // se le agrega una reserva
        _ranking.insert({cantidad_antes +1, cliente})// lo guardo en el set
            }else{
            //el cliente es nuevo y no tenia reservas anteriores y es su primera
            _ranking_por_cliente[cliente] = 1; // lo creo en el map 
            _ranking.insert({1, cliente}); // lo incorporo al set de mas frecuentes
        
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

vector<string> Agenda::clientes_frecuentes(int k) const { //O(k)
   vector<string> resultado;
    auto it = _ranking.rbegin();
    for(int i =0; i< k && it != _ranking.end() ; i++ , ++it){
        resultado.pushback(it->second); //el nombre del cliente
    }
    return resultado;
}
    
