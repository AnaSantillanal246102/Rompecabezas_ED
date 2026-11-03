#ifndef ESTADO_H
#define ESTADO_H

class Estado {
private:
    char tablero[9];
    Estado* parent;
    char movimiento;   // 'U', 'D', 'L', 'R' o ' ' si es el inicial

public:
    Estado(const char t[9]);

    // Constructor de copia
    Estado(const Estado& otro);

    // Evitar asignaciones accidentales de punteros
    Estado& operator=(const Estado& otro) = delete;

    int posicionHueco() const;
    bool esIgual(const Estado& otro) const;
    void imprimir() const;

    Estado* getParent() const;
    void setParent(Estado* p);

    char getMovimiento() const;
    void setMovimiento(char m);
    Estado* mover(char dir);
};

#endif