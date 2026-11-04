typedef struct {
    double x;
    double y;
} Ponto;

typedef struct {
    Ponto inferior_esquerdo;
    Ponto superior_direito;
} Retangulo;

double area(Retangulo r) {
    /*
        inferior esquerdo (0,0)
        superior direito (10, 10)

        area = (superior_direito.y - inferior_esquerdo.y) * (superior_direito.x - superior_direito.x) 
    */

    return (r.superior_direito.y - r.inferior_esquerdo.y) * (r.superior_direito.x - r.inferior_esquerdo.x);
}
int contem(Retangulo r, Ponto p) {
    if (p.x >= r.inferior_esquerdo.x && p.x <= r.superior_direito.x &&
        p.y >= r.inferior_esquerdo.y && p.y <= r.superior_direito.y) {
            return 1;
        }
    return 0;
}