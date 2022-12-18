#include <iostream>
#include <math.h>
using namespace std;

class complexe
{
private:
    float rel;
    float img;

public:
    complexe(float, float);
    bool operator==(complexe);
    void afficher();
    complexe operator+(complexe);
    complexe operator-(complexe);
    complexe operator*(complexe);
    complexe operator/(complexe);
};

void complexe::afficher()
{
    // faire tous les posibilte de L'ecriture d'in nombre complexe
    if (rel == 0 && img != 0)
    {
        cout << "votre nombre complexe est => Z=i(" << img << ")" << endl;
    }
    else if (rel != 0 && img == 0)
    {
        cout << "votre nombre complexe est => Z=" << rel << endl;
    }
    else
    {
        cout << "votre nombre complexe est => Z=(" << rel << ")"
             << "+i(" << img << ")" << endl;
    }
}

complexe::complexe(float a, float b)
{
    rel = a;
    img = b;
}

bool complexe::operator==(complexe b)
{
    return rel == b.rel && img == b.img;
}

complexe complexe::operator+(complexe b)
{
    complexe c(rel + b.rel, img + b.img);
    return c;
}

complexe complexe::operator-(complexe b)
{
    complexe c(rel - b.rel, img - b.img);
    return c;
}

complexe complexe::operator*(complexe b)
{
    complexe c((rel * b.rel) - (img * b.img), (rel * b.img) + (img * b.rel));
    return c;
}

complexe complexe::operator/(complexe b)
{
    complexe c(((rel * b.rel) + (img * b.img)) / (pow(b.rel, 2) + pow(b.img, 2)), ((img * b.rel) - (rel * b.img)) / ((pow(b.rel, 2) + pow(b.img, 2))));
    return c;
}

int main(int argc, char const *argv[])
{
    int a, b, c, d, choix;
    cout << "Entrer un nombre reelle de premier nombre complexe: ";
    cin >> a;
    cout << "Entrer un nombre imaginaire de premier nombre complexe: ";
    cin >> b;
    cout << endl;
    cout << endl;
    cout << "Entrer un nombre reelle de deuxieme nombre complexe: ";
    cin >> c;
    cout << "Entrer un nombre imaginaire de deuxieme nombre complexe: ";
    cin >> d;
    complexe c1(a, b);
    complexe c2(c, d);
    do
    {
        cout << "Choisir une operation pour les nombre complexe:" << endl;
        cout << "1-  egalite" << endl;
        cout << "2-  addition" << endl;
        cout << "3-  soustraction" << endl;
        cout << "4-  multiplication" << endl;
        cout << "5-  division" << endl;
        cout << "Votre choix => ";
        cin >> choix;
        if (choix < 1 || choix > 5)
        {
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "            ATTENTION! Tu dois choisir un nombre Entre 1 et 5" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
        }
    } while (choix < 1 || choix > 5);
    if (choix == 1)
    {
        if (c1 == c2)
        {
            cout << "les deux nombres complexe sont egaux" << endl;
        }
        else
        {
            cout << "les deux nombres complexe sont different" << endl;
        }
    }
    if (choix == 2)
        (c1 + c2).afficher();
    if (choix == 3)
        (c1 - c2).afficher();
    if (choix == 4)
        (c1 * c2).afficher();
    if (choix == 5)
        (c1 / c2).afficher();
    return 0;
}
