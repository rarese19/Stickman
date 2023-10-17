#include <bits/stdc++.h>
#include <windows.h>
#include <typeinfo>


using namespace std;

class IOInterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};

class Imbracaminte: public IOInterface{
protected:
    char culoare;
public:
    Imbracaminte();
    Imbracaminte(char culoare);
    Imbracaminte(const Imbracaminte& obj);

    virtual void proprietati() const = 0;

    Imbracaminte& operator = (const Imbracaminte& obj);
    friend istream& operator >> (istream& in, Imbracaminte& obj);
    friend ostream& operator << (ostream& out, const Imbracaminte& obj);

    istream& citire(istream& in){
        cout<<"Introduceti culoarea (g/a/v/r): ";
        in>>this->culoare;
        while (strchr("gavr", this->culoare) == NULL){
            cout<<"Introduceti culoarea (g/a/v/r): ";
            in>>this->culoare;
        }
        return in;
    }

    ostream& afisare(ostream& out) const{
        out<<"Culoare: ";
        if (this->culoare == 'g')
            out<<"Galben\n";
        if (this->culoare == 'a')
            out<<"Albastru\n";
        if (this->culoare == 'v')
            out<<"Verde\n";
        if (this->culoare == 'r')
            out<<"Rosu\n";
        return out;
    }

    virtual char getCuloare() {}
    virtual bool getManeca() {}
    virtual bool getPantaloni() {}
    virtual bool getPapuci() {}
    virtual bool getMarimePapuci() {}
    virtual int getInaltime() {}

    virtual void setPalarie(bool) {}
    virtual void setInaltime(bool) {}
    virtual void setManeca(bool) {}
    virtual void setScurti(int) {}
    virtual void setMarimePapuci(bool) {}
    virtual void setPantaloni(bool) {}
    virtual void setPapuci(bool) {}


    void setCuloare(char culoare) {this->culoare = culoare;}

    virtual ~Imbracaminte() {};
};

Imbracaminte::Imbracaminte(){
    this->culoare = '/';
}

Imbracaminte::Imbracaminte(char culoare){
    this->culoare = culoare;
}

Imbracaminte::Imbracaminte(const Imbracaminte& obj){
    this->culoare = obj.culoare;
}

Imbracaminte& Imbracaminte::operator = (const Imbracaminte& obj){
    if (this != &obj){
        this->culoare = obj.culoare;
    }
    return *this;
}

class Palarie: virtual public Imbracaminte{
protected:
    int inaltime;
public:
    Palarie();
    Palarie(char culoare, int inaltime);
    Palarie(const Palarie& obj);

    Palarie& operator = (const Palarie& obj);

    istream& citire(istream& in){
        this->Imbracaminte::citire(in);
        cout<<"Inaltime (1/2): "; in>>this->inaltime;
        return in;
    }

    ostream& afisare(ostream& out) const{
        this->Imbracaminte::afisare(out);
        out<<"Inaltime: "; out<<this->inaltime<<endl;
        return out;
    }

    char getCuloare() {return this->culoare;}
    int getInaltime() {return this->inaltime;}

    void setPalarie(int inaltime) {this->inaltime = inaltime;}
    void setCuloare(char culoare) {this->culoare = culoare;}

    void proprietati() const {
        cout<<"Culoare: ";
        if (this->culoare == 'g')
            cout<<"Galben\n";
        if (this->culoare == 'a')
            cout<<"Albastru\n";
        if (this->culoare == 'v')
            cout<<"Verde\n";
        if (this->culoare == 'r')
            cout<<"Rosu\n";
        cout<<"Inaltime: "; cout<<this->inaltime<<endl;
    }

    virtual ~Palarie() {};
};

Palarie::Palarie(): Imbracaminte(){
    this->inaltime = 0;
}

Palarie::Palarie(char culoare, int inaltime): Imbracaminte(culoare){
    this->inaltime = inaltime;
}

Palarie::Palarie(const Palarie& obj): Imbracaminte(obj){
    this->inaltime = obj.inaltime;
}

Palarie& Palarie::operator = (const Palarie& obj){
    if (this != &obj){
        Imbracaminte::operator = (obj);
        this->inaltime = obj.inaltime;
    }
    return *this;
}

class Top: virtual public Imbracaminte{
protected:
    bool maneca;
public:
    Top();
    Top(char culoare, bool maneca);
    Top(const Top& obj);

    Top& operator = (const Top& obj);

    istream& citire(istream& in){
        this->Imbracaminte::citire(in);
        cout<<"Are maneca?(0/1) "; in>>this->maneca;
        return in;
    }

    ostream& afisare(ostream& out) const{
        this->Imbracaminte::afisare(out);
        out<<"Are maneca: ";
        if (this->maneca == 1)
            out<<"da";
        else
            out<<"nu";
        out<<endl;
        return out;
    }

    bool getManeca() {return this->maneca;}
    char getCuloare() {return this->culoare;}

    void setManeca(bool maneca) {this->maneca = maneca;}
    void setCuloare(char culoare) {this->culoare = culoare;}

    void proprietati() const {
        cout<<"Culoare: ";
        if (this->culoare == 'g')
            cout<<"Galben\n";
        if (this->culoare == 'a')
            cout<<"Albastru\n";
        if (this->culoare == 'v')
            cout<<"Verde\n";
        if (this->culoare == 'r')
            cout<<"Rosu\n";
        cout<<"Maneca este: ";
        if (this->maneca == 1)
            cout<<"lunga\n";
        else cout<<"scurta\n";
    }

    virtual ~Top() {};
};

Top::Top(): Imbracaminte(){
    this->maneca = 0;
}

Top::Top(char culoare, bool maneca): Imbracaminte(culoare){
    this->maneca = maneca;
}

Top::Top(const Top& obj): Imbracaminte(obj){
    this->maneca = obj.maneca;
}

Top& Top::operator = (const Top& obj){
    if (this != &obj){
        Imbracaminte::operator = (obj);
        this->maneca = obj.maneca;
    }
    return *this;
}

class Bottom: virtual public Imbracaminte{
protected:
    bool scurt;
public:
    Bottom();
    Bottom(char culoare, bool scurt);
    Bottom(const Bottom& obj);

    Bottom& operator = (const Bottom& obj);

    istream& citire(istream& in){
        this->Imbracaminte::citire(in);
        cout<<"Sunt scurti? (0/1) ";
        in>>this->scurt;
        return in;
    }

    ostream& afisare(ostream& out) const{
        this->Imbracaminte::afisare(out);
        out<<"Sunt scurti: ";
        if (this->scurt == 1)
            out<<"da";
        else
            out<<"nu";
        out<<endl;
        return out;
    }

    bool getPantaloni() {return this->scurt;}
    char getCuloare() {return this->culoare;}

    void setScurti(bool scurt) {this->scurt = scurt;}
    void setCuloare(char culoare) {this->culoare = culoare;}

    void proprietati() const {
        cout<<"Culoare: ";
        if (this->culoare == 'g')
            cout<<"Galben\n";
        if (this->culoare == 'a')
            cout<<"Albastru\n";
        if (this->culoare == 'v')
            cout<<"Verde\n";
        if (this->culoare == 'r')
            cout<<"Rosu\n";
        cout<<"Sunt scurti: ";
        if (this->scurt == 1)
            cout<<"da\n";
        else cout<<"nu\n";
    }

    virtual ~Bottom() {};
};

Bottom::Bottom(): Imbracaminte(){
    this->scurt = 0;
}

Bottom::Bottom(char culoare, bool scurt): Imbracaminte(culoare){
    this->scurt = 0;
}

Bottom::Bottom(const Bottom& obj): Imbracaminte(obj){
    this->scurt = obj.scurt;
}

Bottom& Bottom::operator = (const Bottom& obj){
    if (this != &obj){
        Imbracaminte::operator = (obj);
        this->scurt = obj.scurt;
    }
    return *this;
}

class Shoes: virtual public Imbracaminte{
protected:
    bool mari;
public:
    Shoes();
    Shoes(char culoare, bool mari);
    Shoes(const Shoes& obj);

    Shoes& operator = (const Shoes& obj);

    istream& citire(istream& in){
        this->Imbracaminte::citire(in);
        cout<<"Sunt mari? (0/1) "; in>>this->mari;
        return in;
    }

    ostream& afisare(ostream& out) const{
        this->Imbracaminte::afisare(out);
        out<<"Sunt mari: ";
        if (this->mari == 1)
            out<<"da";
        else
            out<<"nu";
        out<<endl;
        return out;
    }

    bool getMarimePapuci() {return this->mari;}
    char getCuloare() {return this->culoare;}

    void setMarimePapuci(bool mari) {this->mari = mari;}
    void setCuloare(char culoare) {this->culoare = culoare;}

    void proprietati() const {
        cout<<"Culoare: ";
        if (this->culoare == 'g')
            cout<<"Galben\n";
        if (this->culoare == 'a')
            cout<<"Albastru\n";
        if (this->culoare == 'v')
            cout<<"Verde\n";
        if (this->culoare == 'r')
            cout<<"Rosu\n";
        cout<<"Sunt mari: ";
        if (this->mari == 1)
            cout<<"da\n";
        else cout<<"nu\n";
    }

    virtual ~Shoes() {};
};

Shoes::Shoes(): Imbracaminte(){
    this->mari = 0;
}

Shoes::Shoes(char culoare, bool mari): Imbracaminte(culoare){
    this->mari = mari;
}

Shoes::Shoes(const Shoes& obj): Imbracaminte(obj){
    this->mari = obj.mari;
}

Shoes& Shoes::operator = (const Shoes& obj){
    if (this != &obj){
        Imbracaminte::operator = (obj);
        this->mari = obj.mari;
    }
    return *this;
}

class Compleu: public Palarie, public Top, public Bottom, public Shoes{
    bool papuci;
public:
    Compleu();
    Compleu(char culoare, int inaltime, bool maneca, bool scurt, bool mari, bool papuci);
    Compleu(const Compleu& obj);

    Compleu& operator = (const Compleu& obj);

    istream& citire(istream& in) {
        this->Imbracaminte::citire(in);
        cout<<"Inaltimea palariei (1/2): ";
        in>>this->inaltime;
        cout<<"Are maneca?(0/1) ";
        in>>this->maneca;
        cout<<"Are pantaloni scurti?(0/1) ";
        in>>this->scurt;
        cout<<"Sunt papucii inclusi?(0/1) ";
        in>>this->papuci;
        if (this->papuci == 1){
            cout<<"Are papuci mari?(0/1) ";
            in>>this->mari;
        }
        else this->mari = 0;
        return in;
    }

    ostream& afisare(ostream& out) const{
        this->Imbracaminte::afisare(out);
        out<<"Inaltimea palariei: "<<this->inaltime<<endl;
        out<<"Are maneca: ";
        if (this->maneca == 1)
            out<<"da"<<endl;
        else
            out<<"nu"<<endl;
        out<<"Are pantaloni lungi: ";
        if (this->scurt == 1)
            out<<"nu"<<endl;
        else
            out<<"da"<<endl;
        if (this->papuci == 1)
            out<<"Papusi sunt inclusi.\n";
        else
            out<<"Papucii nu sunt inclusi.\n";
        out<<"Are papuci mari: ";
        if (this->mari == 1)
            out<<"da"<<endl;
        else
            out<<"nu"<<endl;

        return out;
    }

    char getCuloare() {return this->culoare;}
    int getInaltime() {return this->inaltime;}
    bool getMarimePapuci() {return this->mari;}
    bool getManeca() {return this->maneca;}
    bool getPantaloni() {return this->scurt;}
    bool getPapuci() {return this->papuci;}

    void setCuloare(char culoare) {this->culoare = culoare;}
    void setInaltime(int inaltime) {this->inaltime = inaltime;}
    void setMarimePapuci(bool mari) {this->mari = mari;}
    void setManeca(bool maneca) {this->maneca = maneca;}
    void setPantaloni(bool scurt) {this->scurt = scurt;}
    void setPapuci(bool papuci) {this->papuci = papuci;}

    void proprietati() const {
        cout<<"Culoare: ";
        if (this->culoare == 'g')
            cout<<"Galben\n";
        if (this->culoare == 'a')
            cout<<"Albastru\n";
        if (this->culoare == 'v')
            cout<<"Verde\n";
        if (this->culoare == 'r')
            cout<<"Rosu\n";
        cout<<"Inaltime: ";
        cout<<this->inaltime<<endl;
        cout<<"Maneca: ";
        if (this->maneca == 1)
            cout<<"da\n";
        else cout<<"nu\n";
        cout<<"Pantaloni scurti: ";
        if (this->scurt == 1)
            cout<<"da\n";
        else cout<<"nu\n";
        if (this->papuci == 0)
            cout<<"Papucii nu sunt inclusi\n";
        else {
            if (this->mari == 1)
                cout<<"Papucii sunt mari\n";
            else cout<<"Papucii nu sunt mari\n";
        }
    }

    ~Compleu() {};
};

Compleu::Compleu(){
    this->papuci = 1;
}

Compleu::Compleu(char culoare, int inaltime, bool maneca, bool scurt, bool mari, bool papuci):
Imbracaminte(culoare), Palarie(culoare, inaltime), Top(culoare, maneca),
Bottom(culoare, scurt), Shoes(culoare, mari){
    this->papuci = 1;
}

Compleu::Compleu(const Compleu& obj): Imbracaminte(obj), Palarie(obj), Top(obj), Bottom(obj), Shoes(obj){
    this->papuci = obj.papuci;
}

Compleu& Compleu::operator = (const Compleu& obj){
    if (this != &obj){
        Palarie::operator = (obj);
        Top::operator = (obj);
        Bottom::operator = (obj);
        Shoes::operator = (obj);
        this->papuci = obj.papuci;
    }
    return *this;
}

istream& operator >> (istream& in, Imbracaminte& obj){
    return obj.citire(in);
}

ostream& operator << (ostream& out, const Imbracaminte& obj){
    return obj.afisare(out);
}

class Outfit {
    Imbracaminte* haina;
    int rating;

public:
    friend ostream& operator << (ostream& out, const Outfit& obj);
    friend istream& operator >> (istream& in, Outfit& obj);

    void calculeazaRating();
    int getRating() {return this->rating;}
    Imbracaminte* getHaina() {return this->haina;}

};

ostream& operator << (ostream& out, const Outfit& obj){
    out<<*obj.haina;

    return out;
}

istream& operator >> (istream& in, Outfit& obj){
    cout<<"Introduceti tipul de haina: (palarie, top, pantaloni, pantofi) ";
    string a;
    cin>>a;
    try{
    if (a == "palarie"){
        obj.haina = new Palarie();
        cin>>*obj.haina;
    }

    if (a == "top"){
        obj.haina = new Top();
        cin>>*obj.haina;
    }

    if (a == "pantaloni"){
        obj.haina = new Bottom();
        cin>>*obj.haina;
    }

    if (a == "pantofi"){
        obj.haina = new Shoes();
        cin>>*obj.haina;
    }

    throw string("Nu exista acest tip de haina!");
    }
    catch(const string& e){
        cout<<e<<endl;
    }

    return in;
}

void Outfit::calculeazaRating(){
    char c = this->haina->getCuloare();
    if (c == 'g')
        this->rating = 1;
    if (c == 'a')
        this->rating = 3;
    if (c == 'v')
        this->rating = 4;
    if (c == 'r')
        this->rating = 2;

    if (dynamic_cast<Palarie*>(this->haina) != NULL){
        int inaltime  = dynamic_cast<Palarie*>(this->haina)->getInaltime();

        if (inaltime == 2)
            this->rating += 6;
        else this->rating += 3;
    }

    if (dynamic_cast<Top*>(this->haina) != NULL){
        bool maneca = dynamic_cast<Top*>(this->haina)->getManeca();

        if (maneca == 1)
            this->rating += 6;
        else this->rating += 3;
    }

    if (dynamic_cast<Bottom*>(this->haina) != NULL){
        bool scurt = dynamic_cast<Bottom*>(this->haina)->getPantaloni();

        if (scurt == 1)
            this->rating += 3;
        else this->rating += 6;
    }

    if (dynamic_cast<Shoes*>(this->haina) != NULL){
        bool mari = dynamic_cast<Shoes*>(this->haina)->getPapuci();

        if (mari == 1)
            this->rating += 3;
        else this->rating += 6;
    }

    if (dynamic_cast<Compleu*>(this->haina) != NULL){
        Compleu* c = dynamic_cast<Compleu*>(this->haina);
        bool papuci = c->getPapuci();
        int inaltime = c->getInaltime();
        bool maneca = c->getManeca();
        bool scurt = c->getPantaloni();
        bool mari = c->getMarimePapuci();

        if (inaltime == 2)
            this->rating += 2;
        else this->rating += 1;

        if (maneca == 1)
            this->rating += 2;
        else this->rating += 1;

        if (scurt == 1)
            this->rating += 1;
        else this->rating += 2;

        if (papuci == 1){
            if (mari == 1)
                this->rating += 1;
            else this->rating += 2;
            this->rating += 2;
        }


        if (this->rating > 10)
            this->rating = 10;
    }
}


class Stickman{
    static int contorId;
    const int idStickman;
    int rating;
    bool compleu; Imbracaminte* c = NULL;
    bool palarie; Imbracaminte* p = NULL;
    bool top; Imbracaminte* t = NULL;
    bool bottom; Imbracaminte* b = NULL;
    bool shoes; Imbracaminte* s = NULL;
public:
    Stickman();
    Stickman(bool compleu, bool palarie, bool top, bool bottom, bool shoes);
    Stickman(const Stickman& obj);

    Stickman& operator = (const Stickman& obj);
    friend istream& operator >> (istream& in, Stickman& obj);
    friend ostream& operator << (ostream& out, const Stickman& obj);

    void calculeazaRating();

    int getIdStickman() const {return this->idStickman;}
    bool getCompleu() const {return this->compleu;}
    bool getPalarie() const {return this->palarie;}
    bool getTop() const {return this->top;}
    bool getPantaloni() const {return this->bottom;}
    bool getPapuci() const {return this->shoes;}
    int getRating() const {return this->rating;}

    bool getManeca() const {return this->t->getManeca();}
    bool getManecaCompleu() const {return this->c->getManeca();}
    bool getLungime() const {return this->b->getPantaloni();}
    bool getLungimeCompleu() const {return this->c->getPantaloni();}
    bool getMarimePapuci() const {return this->s->getMarimePapuci();}
    bool getMarimePapuciCompleu() const {return this->c->getMarimePapuci();}
    bool getPapuciInclusiCompleu() const {return this->c->getPapuci();}

    Imbracaminte* getCompleuImbracaminte() const {return this->c;}
    Imbracaminte* getPalarieImbracaminte() const {return this->p;}
    Imbracaminte* getTopImbracaminte() const {return this->t;}
    Imbracaminte* getBottomImbracaminte() const {return this->b;}
    Imbracaminte* getShoesImbracaminte() const {return this->s;}

    void setCuloareCompleu(char culoare) {this->c->setCuloare(culoare);}
    void setInaltimeCompleu(int inaltime) {this->c->setInaltime(inaltime);}
    void setMarimePapuciCompleu(bool mari) {if (this->getPapuciInclusiCompleu() == 1) this->c->setMarimePapuci(mari);}
    void setManecaCompleu(bool maneca) {this->c->setManeca(maneca);}
    void setPantaloniCompleu(bool scurt) {this->c->setPantaloni(scurt);}
    void setPapuciCompleu(bool papuci) {if (papuci == 0) this->setMarimePapuciCompleu(0); this->c->setPapuci(papuci);}
    void setPalarie(bool palarie);
    void setTop(bool top);
    void setBottom(bool bottom);
    void setShoes(bool shoes);
    void setCuloarePalarie(char culoare) {this->p->setCuloare(culoare);}
    void setInaltimePalarie(int inaltime) {this->p->setPalarie(inaltime);}
    void setCuloareTop(char culoare) {this->t->setCuloare(culoare);}
    void setManecaTop(bool maneca) {this->t->setManeca(maneca);}
    void setCuloareBottom(char culoare) {this->b->setCuloare(culoare);}
    void setScrutiBottom(bool scurti) {this->b->setScurti(scurti);}
    void setCuloarePapuci(char culoare) {this->s->setCuloare(culoare);}
    void setMarimePapuci(bool mari) {this->s->setMarimePapuci(mari);}

    void random();
    void proprietati();

    ~Stickman();
};

Stickman::Stickman(): idStickman(contorId++){
    this->compleu = 0;
    this->palarie = 0;
    this->top = 0;
    this->bottom = 0;
    this->shoes = 0;
    this->rating = 0;
}

Stickman::Stickman(bool compleu, bool palarie, bool top, bool bottom, bool shoes): idStickman(contorId++){
    this->compleu = compleu;
    if (this->compleu == 1){
        this->palarie = 0;
        this->top = 0;
        this->bottom = 0;
        this->shoes = 0;
    }
    else{
        this->palarie = palarie;
        this->top = top;
        this->bottom = bottom;
        this->shoes = shoes;
    }
}

Stickman::Stickman(const Stickman& obj):idStickman(obj.idStickman){
    this->compleu = obj.compleu;
    if (this->compleu == 1)
        this->c = obj.c;
    this->palarie = obj.palarie;
    if (this->palarie == 1)
        this->p = obj.p;
    this->top = obj.top;
    if (this->top == 1)
        this->t = obj.t;
    this->bottom = obj.bottom;
    if (this->bottom == 1)
        this->b = obj.b;
    this->shoes = obj.shoes;
    if (this->shoes == 1)
        this->s = obj.s;
}

void Stickman::calculeazaRating(){
    if (this->compleu == 1){
        char c = this->c->getCuloare();
        if (c == 'g')
            this->rating = 1;
        if (c == 'a')
            this->rating = 3;
        if (c == 'v')
            this->rating = 4;
        if (c == 'r')
            this->rating = 2;

        int inaltime = this->c->getInaltime();
        if (inaltime == 1)
            this->rating += 1;
        else this->rating += 2;

        bool maneca = this->c->getManeca();
        if (maneca == 1)
            this->rating += 2;
        else this->rating += 1;

        bool scurt = this->c->getPantaloni();
        if (scurt == 1)
            this->rating += 1;
        else this->rating += 2;

        bool papuci = this->c->getPapuci();
        if (papuci == 1){
            if (this->c->getMarimePapuci() == 1)
                this->rating += 2;
            else this->rating += 1;
        }
    }

    if (this->palarie == 1){
        char c = this->p->getCuloare();
        if (c == 'g')
            this->rating = 1;
        if (c == 'a')
            this->rating = 3;
        if (c == 'v')
            this->rating = 4;
        if (c == 'r')
            this->rating = 2;

        int inaltime = this->p->getInaltime();
        if (inaltime == 1)
            this->rating += 1;
        else this->rating += 2;
    }

    if (this->top == 1){
        char c = this->t->getCuloare();
        if (c == 'g')
            this->rating = 1;
        if (c == 'a')
            this->rating = 3;
        if (c == 'v')
            this->rating = 4;
        if (c == 'r')
            this->rating = 2;

        bool maneca = this->t->getManeca();
        if (maneca == 1)
            this->rating += 2;
        else this->rating += 1;
    }

    if (this->bottom == 1){
        char c = this->b->getCuloare();
        if (c == 'g')
            this->rating = 1;
        if (c == 'a')
            this->rating = 3;
        if (c == 'v')
            this->rating = 4;
        if (c == 'r')
            this->rating = 2;

        bool scurt = this->b->getPantaloni();
        if (scurt == 1)
            this->rating += 1;
        else this->rating += 2;
    }

    if (this->shoes == 1){
        char c = this->s->getCuloare();
        if (c == 'g')
            this->rating = 1;
        if (c == 'a')
            this->rating = 3;
        if (c == 'v')
            this->rating = 4;
        if (c == 'r')
            this->rating = 2;

        bool papuci = this->s->getPapuci();
        if (papuci == 1){
            if (this->s->getMarimePapuci() == 1)
                this->rating += 2;
            else this->rating += 1;
        }
    }
}

Stickman& Stickman::operator = (const Stickman& obj){
    if (this != &obj){
        this->compleu = obj.compleu;
        this->palarie = obj.palarie;
        this->top = obj.top;
        this->bottom = obj.bottom;
        this->shoes = obj.shoes;
        if (this->c != NULL)
            delete this->c;
        this->c = obj.c;
        if (this->p != NULL)
            delete this->p;
        this->p = obj.p;
        if (this->t != NULL)
            delete this->t;
        this->t = obj.t;
        if (this->b != NULL)
            delete this->b;
        this->b = obj.b;
        if (this->s != NULL)
            delete this->s;
        this->s = obj.s;
    }
    return *this;
}

istream& operator >> (istream& in, Stickman& obj){
    if (obj.c != NULL){
        delete obj.c;
        obj.c = NULL;
    }
    if (obj.p != NULL){
        delete obj.p;
        obj.p = NULL;
    }
    if (obj.t != NULL){
        delete obj.t;
        obj.t = NULL;
    }
    if (obj.b != NULL){
        delete obj.b;
        obj.b = NULL;
    }
    if (obj.s != NULL){
        delete obj.s;
        obj.s = NULL;
    }
    cout<<"Are compleu?(0/1) "; in>>obj.compleu;
    if (obj.compleu == 1){
        obj.c = new Compleu();
        cin>>*obj.c;
        obj.palarie = 0;
        obj.top = 0;
        obj.bottom = 0;
        obj.shoes = 0;
    }
    else{
        cout<<"Are palarie?(0/1) "; in>>obj.palarie;
        if (obj.palarie == 1){
            obj.p = new Palarie();
            cin>>*obj.p;
        }
        cout<<"Are top?(0/1) "; in>>obj.top;
        if (obj.top == 1){
            obj.t = new Top();
            cin>>*obj.t;
        }
        cout<<"Are pantaloni?(0/1) "; in>>obj.bottom;
        if (obj.bottom == 1){
            obj.b = new Bottom();
            cin>>*obj.b;
        }
        cout<<"Are papuci?(0/1) "; in>>obj.shoes;
        if (obj.shoes == 1){
            obj.s = new Shoes();
            cin>>*obj.s;
        }
    }
    return in;
}

ostream& operator << (ostream& out, const Stickman& obj){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k;
    if (obj.c != NULL){
        if (obj.c->getCuloare() == 'r')
            k = 12;
        if (obj.c->getCuloare() == 'a')
            k = 11;
        if (obj.c->getCuloare() == 'g')
            k = 14;
        if (obj.c->getCuloare() == 'v')
            k = 10;
        if (obj.c->getMarimePapuci() == 0){
            SetConsoleTextAttribute(hConsole, k);
            if (obj.c->getInaltime() == 1){
                cout<<"   _\n"<<"  /_\\"<<endl;
            }
            else if (obj.c->getInaltime() == 2){
                cout<<"   _\n"<<"  | |\n"<<"  |_|\n";
            }
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"   O\n";
            SetConsoleTextAttribute(hConsole, k);
            cout<<"  /Y\\"<<endl;
            if (obj.c->getManeca() == 1){
                SetConsoleTextAttribute(hConsole, k);
                cout<<" / | \\"<<endl;
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                cout<<" / ";
                SetConsoleTextAttribute(hConsole, k);
                cout<<"|";
                SetConsoleTextAttribute(hConsole, 15);
                cout<<" \\"<<endl;;
            }
            SetConsoleTextAttribute(hConsole, k);
            cout<<"  / \\"<<endl;
            if (obj.c->getPapuci() == 1){
                if (obj.c->getPantaloni() == 0){
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"_/   \\_"<<endl;
                }
                else if (obj.c->getPantaloni() == 1){
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"_";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"_"<<endl;
                }
            }
            else if (obj.c->getPapuci() == 0){
                if (obj.c->getPantaloni() == 0){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"_";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"_"<<endl;
                }
                else if (obj.c->getPantaloni() == 1){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"_/   \\_"<<endl;
                }
            }

        }
        else if (obj.c->getMarimePapuci() == 1){
            SetConsoleTextAttribute(hConsole, k);
            if (obj.c->getInaltime() == 1){
                cout<<"    _\n"<<"   /_\\"<<endl;
            }
            else if (obj.c->getInaltime() == 2){
                cout<<"    _\n"<<"   | |\n"<<"   |_|\n";
            }
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"    O\n";
            SetConsoleTextAttribute(hConsole, k);
            cout<<"   /Y\\"<<endl;
            if (obj.c->getManeca() == 1){
                cout<<"  / | \\"<<endl;
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                cout<<"  /";
                SetConsoleTextAttribute(hConsole, k);
                cout<<" |";
                SetConsoleTextAttribute(hConsole, 15);
                cout<<" \\"<<endl;
            }
            SetConsoleTextAttribute(hConsole, k);
            cout<<"   / \\"<<endl;
            if (obj.c->getPapuci() == 1){
                if (obj.c->getPantaloni() == 0){
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"__/   \\__"<<endl;
                }
                else if (obj.c->getPantaloni() == 1){
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"__";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"__"<<endl;
                }
            }
            else if (obj.c->getPapuci() == 0){
                if (obj.c->getPantaloni() == 0){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"__";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"__"<<endl;;
                }
                else if (obj.c->getPantaloni() == 1){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"__/   \\__"<<endl;
                }
            }
        }
    }
    else if (obj.c == NULL){
        if (obj.p != NULL){
            if (obj.p->getCuloare() == 'r')
                k = 12;
            if (obj.p->getCuloare() == 'a')
                k = 11;
            if (obj.p->getCuloare() == 'g')
                k = 14;
            if (obj.p->getCuloare() == 'v')
                k = 10;
            if (obj.shoes == 0 || (obj.shoes == 1 && obj.s->getMarimePapuci() == 0)){
                SetConsoleTextAttribute(hConsole, k);
                if (obj.p->getInaltime() == 1){
                    cout<<"   _\n"<<"  /_\\"<<endl;
                }
                else if (obj.p->getInaltime() == 2){
                    cout<<"   _\n"<<"  | |\n"<<"  |_|\n";
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, k);
                if (obj.p->getInaltime() == 1){
                    cout<<"    _\n"<<"   /_\\"<<endl;
                }
                else if (obj.p->getInaltime() == 2){
                    cout<<"    _\n"<<"   | |\n"<<"   |_|\n";
                }
            }
        }
        if (obj.shoes == 0){
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"   O"<<endl;
            if (obj.top == 0){
                SetConsoleTextAttribute(hConsole, 15);
                cout<<"  /Y\\"<<endl;
                cout<<" / | \\"<<endl;
            }
            else {
                if (obj.t->getCuloare() == 'r')
                    k = 12;
                if (obj.t->getCuloare() == 'a')
                    k = 11;
                if (obj.t->getCuloare() == 'g')
                    k = 14;
                if (obj.t->getCuloare() == 'v')
                    k = 10;
                if (obj.t->getManeca() == 0){
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"  /Y\\"<<endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<" / ";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"|";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<" \\"<<endl;
                }
                else {
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"  /Y\\"<<endl;
                    cout<<" / | \\"<<endl;
                }
            }
            if (obj.bottom == 0){
                SetConsoleTextAttribute(hConsole, 15);
                cout<<"  / \\"<<endl;
                cout<<"_/   \\_"<<endl;
            }
            else {
                if (obj.b->getCuloare() == 'r')
                    k = 12;
                if (obj.b->getCuloare() == 'a')
                    k = 11;
                if (obj.b->getCuloare() == 'g')
                    k = 14;
                if (obj.b->getCuloare() == 'v')
                    k = 10;
                SetConsoleTextAttribute(hConsole, k);
                cout<<"  / \\"<<endl;
                if (obj.b->getPantaloni() == 0){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"_";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"_"<<endl;
                }
                else {
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"_/   \\_"<<endl;
                }
            }
        }
        else if (obj.shoes == 1){
            if (obj.s->getMarimePapuci() == 0){
                SetConsoleTextAttribute(hConsole, 15);
                cout<<"   O"<<endl;
                if (obj.top == 0){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"  /Y\\"<<endl;
                    cout<<" / | \\"<<endl;
                }
                else {
                    if (obj.t->getCuloare() == 'r')
                        k = 12;
                    if (obj.t->getCuloare() == 'a')
                        k = 11;
                    if (obj.t->getCuloare() == 'g')
                        k = 14;
                    if (obj.t->getCuloare() == 'v')
                        k = 10;
                    if (obj.t->getManeca() == 0){
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"  /Y\\"<<endl;
                        SetConsoleTextAttribute(hConsole, 15);
                        cout<<" / ";
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"|";
                        SetConsoleTextAttribute(hConsole, 15);
                        cout<<" \\"<<endl;
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"  /Y\\"<<endl;
                        cout<<" / | \\"<<endl;
                    }
                }
                if (obj.bottom == 0){
                    if (obj.s->getCuloare() == 'r')
                        k = 12;
                    if (obj.s->getCuloare() == 'a')
                        k = 11;
                    if (obj.s->getCuloare() == 'g')
                        k = 14;
                    if (obj.s->getCuloare() == 'v')
                        k = 10;
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"  / \\"<<endl;
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"_";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"_"<<endl;
                }
                else {
                    int j;
                    if (obj.b->getCuloare() == 'r')
                        j = 12;
                    if (obj.b->getCuloare() == 'a')
                        j = 11;
                    if (obj.b->getCuloare() == 'g')
                        j = 14;
                    if (obj.b->getCuloare() == 'v')
                        j = 10;
                    if (obj.s->getCuloare() == 'r')
                        k = 12;
                    if (obj.s->getCuloare() == 'a')
                        k = 11;
                    if (obj.s->getCuloare() == 'g')
                        k = 14;
                    if (obj.s->getCuloare() == 'v')
                        k = 10;
                    if (obj.b->getPantaloni() == 0){
                        SetConsoleTextAttribute(hConsole, j);
                        cout<<"  / \\"<<endl;
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"_";
                        SetConsoleTextAttribute(hConsole, j);
                        cout<<"/   \\";
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"_"<<endl;
                    }
                    else if (obj.b->getPantaloni() == 1){
                        SetConsoleTextAttribute(hConsole, j);
                        cout<<"  / \\"<<endl;
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"_";
                        SetConsoleTextAttribute(hConsole, 15);
                        cout<<"/   \\";
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"_"<<endl;
                    }
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, 15);
                cout<<"    O"<<endl;
                if (obj.top == 0){
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"   /Y\\"<<endl;
                    cout<<"  / | \\"<<endl;
                }
                else {
                    if (obj.t->getCuloare() == 'r')
                        k = 12;
                    if (obj.t->getCuloare() == 'a')
                        k = 11;
                    if (obj.t->getCuloare() == 'g')
                        k = 14;
                    if (obj.t->getCuloare() == 'v')
                        k = 10;
                    if (obj.t->getManeca() == 0){
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"   /Y\\"<<endl;
                        SetConsoleTextAttribute(hConsole, 15);
                        cout<<"  / ";
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"|";
                        SetConsoleTextAttribute(hConsole, 15);
                        cout<<" \\"<<endl;
                    }
                    else {
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"   /Y\\"<<endl;
                        cout<<"  / | \\"<<endl;
                    }
                }
                if (obj.bottom == 0){
                    if (obj.s->getCuloare() == 'r')
                        k = 12;
                    if (obj.s->getCuloare() == 'a')
                        k = 11;
                    if (obj.s->getCuloare() == 'g')
                        k = 14;
                    if (obj.s->getCuloare() == 'v')
                        k = 10;
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"   / \\"<<endl;
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"__";
                    SetConsoleTextAttribute(hConsole, 15);
                    cout<<"/   \\";
                    SetConsoleTextAttribute(hConsole, k);
                    cout<<"__"<<endl;
                }
                else {
                    int j;
                    if (obj.b->getCuloare() == 'r')
                        j = 12;
                    if (obj.b->getCuloare() == 'a')
                        j = 11;
                    if (obj.b->getCuloare() == 'g')
                        j = 14;
                    if (obj.b->getCuloare() == 'v')
                        j = 10;
                    if (obj.s->getCuloare() == 'r')
                        k = 12;
                    if (obj.s->getCuloare() == 'a')
                        k = 11;
                    if (obj.s->getCuloare() == 'g')
                        k = 14;
                    if (obj.s->getCuloare() == 'v')
                        k = 10;
                    if (obj.b->getPantaloni() == 0){
                        SetConsoleTextAttribute(hConsole, j);
                        cout<<"   / \\"<<endl;
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"__";
                        SetConsoleTextAttribute(hConsole, j);
                        cout<<"/   \\";
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"__"<<endl;
                    }
                    else{
                        SetConsoleTextAttribute(hConsole, j);
                        cout<<"   / \\"<<endl;
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"__";
                        SetConsoleTextAttribute(hConsole, 15);
                        cout<<"/   \\";
                        SetConsoleTextAttribute(hConsole, k);
                        cout<<"__"<<endl;
                    }
                }
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
    return out;
}

void Stickman::setPalarie(bool palarie){
    this->palarie = palarie;
    if (this->palarie == 0){
        delete this->p;
        this->p = NULL;
    }
    if (this->palarie == 1){
        delete this->p;
        this->p = new Palarie();
        cin>>*this->p;
    }
}

void Stickman::setTop(bool top){
    this->top = top;
    if (this->top == 0){
        delete this->t;
        this->t = NULL;
    }
    if (this->top == 1){
        delete this->t;
        this->t = new Top();
        cin>>*this->t;
    }
}

void Stickman::setBottom(bool bottom){
    this->bottom = bottom;
    if (this->bottom == 0){
        delete this->b;
        this->b = NULL;
    }
    if (this->bottom == 1){
        delete this->b;
        this->b = new Bottom();
        cin>>*this->b;
    }
}

void Stickman::setShoes(bool shoes){
    this->shoes = shoes;
    if (this->shoes == 0){
        delete this->s;
        this->s = NULL;
    }
    if (this->shoes == 1){
        delete this->s;
        this->s = new Shoes();
        cin>>*this->s;
    }
}

void Stickman::random(){
    srand((unsigned) time(NULL));
    int i = rand() % 10 + 1;
    if (i <= 5){
        this->compleu = 1;
        this->c = new Compleu();
        i = rand() % 10 + 1;
        if (i == 1 || i == 2)
            this->setCuloareCompleu('g');
        if (i == 3 || i == 4)
            this->setCuloareCompleu('a');
        if (i == 5 || i == 6 || i == 9 || i == 10)
            this->setCuloareCompleu('v');
        if (i == 7 || i == 8)
            this->setCuloareCompleu('r');
        i = rand() % 10 + 1;
        if (i <= 5)
            this->setInaltimeCompleu(1);
        else this->setInaltimeCompleu(2);
        i = rand() % 10 + 1;
        if (i <= 5)
            this->setManecaCompleu(0);
        else this->setManecaCompleu(1);
        i = rand() % 10 + 1;
        if (i <= 5)
            this->setPantaloniCompleu(0);
        else this->setPantaloniCompleu(1);
        i = rand() % 10 + 1;
        if (i <= 5)
            this->setPapuciCompleu(0);
        else this->setPapuciCompleu(1);
        i = rand() % 10 + 1;
        if (i <= 5)
            this->setMarimePapuciCompleu(0);
        else this->setMarimePapuciCompleu(1);
    }
    else this->compleu = 0;
    if (this->compleu == 0){
        i = rand() % 10 + 1;
        if (i <= 5){
            this->palarie = 1;
            this->p = new Palarie();
            i = rand() % 10 + 1;
            if (i == 1 || i == 2)
                this->setCuloarePalarie('g');
            if (i == 3 || i == 4)
                this->setCuloarePalarie('a');
            if (i == 5 || i == 6 || i == 9 || i == 10)
                this->setCuloarePalarie('v');
            if (i == 7 || i == 8)
                this->setCuloarePalarie('r');
            i = rand() % 10 + 1;
            if (i <= 5)
                this->setInaltimePalarie(1);
            else this->setInaltimePalarie(2);
        }
        else this->palarie = 0;
        i = rand() % 10 + 1;
        if (i <= 5){
            this->top = 1;
            this->t = new Top();
            i = rand() % 10 + 1;
            if (i == 1 || i == 2)
                this->setCuloareTop('g');
            if (i == 3 || i == 4)
                this->setCuloareTop('a');
            if (i == 5 || i == 6 || i == 9 || i == 10)
                this->setCuloareTop('v');
            if (i == 7 || i == 8)
                this->setCuloareTop('r');
            i = rand() % 10 + 1;
            if (i <= 5)
                this->setManecaTop(0);
            else this->setManecaTop(1);
        }
        else this->top = 0;
        i = rand() % 10 + 1;
        if (i <= 5){
            this->bottom = 1;
            this->b = new Bottom();
            i = rand() % 10 + 1;
            if (i == 1 || i == 2)
                this->setCuloareBottom('g');
            if (i == 3 || i == 4)
                this->setCuloareBottom('a');
            if (i == 5 || i == 6 || i == 9 || i == 10)
                this->setCuloareBottom('v');
            if (i == 7 || i == 8)
                this->setCuloareBottom('r');
            i = rand() % 10 + 1;
            if (i <= 5)
                this->setScrutiBottom(0);
            else this->setScrutiBottom(1);
        }
        else this->bottom = 0;
        i = rand() % 10 + 1;
        if (i <= 5){
            this->shoes = 1;
            this->s = new Shoes();
            i = rand() % 10 + 1;
            if (i == 1 || i == 2)
                this->setCuloarePapuci('g');
            if (i == 3 || i == 4)
                this->setCuloarePapuci('a');
            if (i == 5 || i == 6 || i == 9 || i == 10)
                this->setCuloarePapuci('v');
            if (i == 7 || i == 8)
                this->setCuloarePapuci('r');
            i = rand() % 10 + 1;
            if (i <= 5)
                this->setMarimePapuci(0);
            else this->setMarimePapuci(1);
        }
        else this->shoes = 0;
    }
}

void Stickman::proprietati(){
    if (this->compleu == 1){
        this->c->proprietati();
    }
    else {
        if (this->palarie == 1){
            cout<<"PALARIE: \n";
            this->p->proprietati();
        }
        if (this->top == 1){
            cout<<"TOP: \n";
            this->t->proprietati();
        }
        if (this->bottom == 1){
            cout<<"BOTTOM: \n";
            this->b->proprietati();
        }
        if (this->shoes == 1){
            cout<<"SHOES: \n";
            this->s->proprietati();
        }
    }
}

Stickman::~Stickman(){
    if (this->c != NULL)
        delete this->c;
    if (this->p != NULL)
        delete this->p;
    if (this->t != NULL)
        delete this->t;
    if (this->b != NULL)
        delete this->b;
    if (this->s != NULL)
        delete this->s;
}

int Stickman::contorId = 0;

vector<Stickman*> stickmen;

template <class Container, class Index, class Information>
void add(Container& container, Index index, Information information){
    container[index].push_back(information);
}


template <class T>
void calculeazaRating(T imbracaminte){
    imbracaminte->calculeazaRating();
    int r = imbracaminte->getRating();
    if (r >= 0 && r <= 5)
        cout<<"Ratingul este "<<r<<", deci produsul este de calitate slaba.\n";
    if (r > 5 && r <= 10)
        cout<<"Ratingul este "<<r<<", deci produsul este de calitate inalta.\n";
    if (r > 10)
        cout<<"WOW!\n";
}

class Magazin{
    static Magazin* obj;
    map<int, vector<Stickman*>, greater<int>> randuriDeManechine;
    map<int, list<Outfit*>, greater<int>> rafturiCuImbracaminte;
    int stoc_palarii, stoc_top, stoc_bottom, stoc_shoes;
    Magazin(){
        stoc_palarii = 0;
        stoc_top = 0;
        stoc_bottom = 0;
        stoc_shoes = 0;
    }
    Magazin(const Magazin&) = delete;
    static int nrOfInstance;


public:
    static Magazin* getInstance() {
        nrOfInstance++;
        if (!obj)
            obj = new Magazin();

        return obj;
    }

    friend ostream& operator << (ofstream& out, Magazin& obj);

    void countStoc();
    void insereaza();
    void afiseaza();
    void sterge();
    void deschide();
    void calculeazaNote();
    void modifica();

    ~Magazin(){
        nrOfInstance--;
        if (nrOfInstance == 0)
            if (obj)
                delete obj;
    }
};

void Magazin::countStoc(){
    stoc_palarii = 0;
    stoc_top = 0;
    stoc_bottom = 0;
    stoc_shoes = 0;
    for (const auto& pair : randuriDeManechine){
        for (const auto& stickman : pair.second){
            if (stickman->getCompleu() == 1){
                stoc_palarii++;
                stoc_top++;
                stoc_bottom++;
                if (stickman->getPapuciInclusiCompleu() == 1)
                    stoc_shoes++;
            }
            else {
                if (stickman->getPalarie() == 1)
                    stoc_palarii++;
                if (stickman->getTop() == 1)
                    stoc_top++;
                if (stickman->getPantaloni() == 1)
                    stoc_bottom++;
                if (stickman->getPapuci() == 1)
                    stoc_shoes++;
            }
        }
    }

    for (const auto& pair : rafturiCuImbracaminte){
        for (const auto& imbracaminte : pair.second){
            Imbracaminte* aux = imbracaminte->getHaina();
            if (dynamic_cast<Palarie*>(aux))
                stoc_palarii++;
            if (dynamic_cast<Top*>(aux))
                stoc_top++;
            if (dynamic_cast<Bottom*>(aux))
                stoc_bottom++;
            if (dynamic_cast<Shoes*>(aux))
                stoc_shoes++;
        }
    }
}

void Magazin::insereaza(){
    system("cls");
    cout<<"Ce inserati?\n";
    cout<<"1. Manechin\n";
    cout<<"2. Imbracaminte\n";
    cout<<"Introduceti alegere: ";
    int alegere; cin>>alegere;
    if (alegere == 1){
        system("cls");
        int rand;
        cout<<"Alegeti randul: ";
        cin>>rand;
        Stickman* a = new Stickman();
        cin>>*a;
        add(randuriDeManechine, rand, a);
    }
    else if (alegere == 2){
        system("cls");
        cout<<"Alegeti raftul: ";
        int raft; cin>>raft;
        Outfit* o = new Outfit();
        cin>>*o;
        add(rafturiCuImbracaminte, raft, o);
    }
}

void Magazin::afiseaza(){
    this->countStoc();
    system("cls");
    cout<<"In stoc, avem: \n";
    cout<<"Palarii: "<<this->stoc_palarii<<"\n";
    cout<<"Tricouri: "<<this->stoc_top<<"\n";
    cout<<"Pantaloni: "<<this->stoc_bottom<<"\n";
    cout<<"Pantofi: "<<this->stoc_shoes<<"\n";
    system("pause");
    system("cls");

    cout<<"Randurile de manechine: \n";

    for (const auto& pair : this->randuriDeManechine){
        cout<<"Randul "<<pair.first<<": \n";
        for (auto const& stickman : pair.second){
            cout<<*stickman<<" ";
            calculeazaRating(stickman);
            cout<<endl;
        }
        cout<<"\n";
    }
    system("pause");
    system("cls");


    if (rafturiCuImbracaminte.size() != 0)
        cout<<"Rafturile cu imbracaminte: \n";

    for (const auto& pair : rafturiCuImbracaminte){
        cout<<"Raftul "<<pair.first<<": \n";
        for (const auto& imbracaminte : pair.second){
            if (dynamic_cast<Palarie*>(imbracaminte->getHaina()))
                cout<<"Palarie ";
            if (dynamic_cast<Top*>(imbracaminte->getHaina()))
                cout<<"Tricou ";
            if (dynamic_cast<Bottom*>(imbracaminte->getHaina()))
                cout<<"Pantaloni ";
            if (dynamic_cast<Shoes*>(imbracaminte->getHaina()))
                cout<<"Pantofi ";
            cout<<endl;
            cout<<*imbracaminte<<" ";
            calculeazaRating(imbracaminte);
            cout<<endl;
        }
    }

    system("pause");
}

void Magazin::sterge() {
    cout<<"Ce stergeti?\n";
    cout<<"1. Manechin\n";
    cout<<"2. Imbracaminte\n";
    cout<<"Introduceti alegere: ";

    int alegere; cin>>alegere;
    if (alegere == 1){
        system("cls");
        cout<<"Randurile de manechine: \n";

        for (const auto& pair : this->randuriDeManechine){
            cout<<"Randul "<<pair.first<<": \n";
            for (auto const& stickman : pair.second){
                cout<<*stickman<<" ";
            }
            cout<<"\n";
        }

        cout<<"Alegeti randul: ";
        int rand; cin>>rand;
        cout<<"Alegeti pozitia: ";
        int pozitie; cin>>pozitie;

        try{
        if (randuriDeManechine.find(rand) == randuriDeManechine.end())
            throw(rand);

        if (randuriDeManechine[rand].size() < pozitie || pozitie < 0)
            throw(pozitie);

        randuriDeManechine[rand].erase(randuriDeManechine[rand].begin() + pozitie - 1);

        cout<<"Elementul a fost sters cu succes!\n";
        if (randuriDeManechine[rand].size() == 0)
            randuriDeManechine.erase(rand);
        system("pause");
        }
        catch(int){
            cout<<"Rand/Pozitie invalida!\n";
        }
    }
    if (alegere == 2){
        system("cls");
        cout<<"Rafturile cu imbracaminte: \n";

        for (const auto& pair : rafturiCuImbracaminte)
            for (const auto& imbracaminte : pair.second)
                cout<<*imbracaminte<<" ";

        cout<<"Alegeti raftul: ";
        int raft; cin>>raft;
        cout<<"Alegeti pozitia: ";
        int pozitie; cin>>pozitie;


        try{
        if (rafturiCuImbracaminte.find(raft) == rafturiCuImbracaminte.end())
            throw(raft);

        if (rafturiCuImbracaminte[raft].size() < pozitie || pozitie < 0)
            throw(pozitie);

        auto list_f = rafturiCuImbracaminte[raft].begin();
        advance(list_f, pozitie - 1);
        rafturiCuImbracaminte[raft].erase(list_f);

        cout<<"Elementul a fost sters cu succes!\n";
        if (rafturiCuImbracaminte[raft].size() == 0)
            rafturiCuImbracaminte.erase(raft);
        system("pause");

        }
        catch(int){
            cout<<"Raft/Pozitie invalida!\n";
        }
    }
}

void Magazin::modifica() {
    system("cls");

    for (auto pair : randuriDeManechine){
        cout<<"Randul "<<pair.first<<": \n";
        for (auto stickman : pair.second){
            cout<<*stickman<<" ";
        }
        cout<<"\n";
    }

    cout<<"Alegeti randul: ";
    int rand; cin>>rand;
    cout<<"Alegeti pozitia: ";
    int pozitie; cin>>pozitie;

    system("cls");
    cout<<"Ce modificati?\n";
    if (randuriDeManechine[rand][pozitie - 1]->getCompleu()){
        cout<<"1. Modifica palaria.\n";
        cout<<"2. Modifica tricoul.\n";
        cout<<"3. Modifica pantalonii.\n";
        cout<<"4. Modifica pantofii.\n";
        cout<<"5. Modifica culoarea.\n";
        cout<<"Introduceti alegerea: ";
        int alegere; cin>>alegere;
        switch (alegere){
            case 1:{
                system("cls");
                cout<<"Alegeti inaltimea (1/2): ";
                cin>>alegere;
                randuriDeManechine[rand][pozitie - 1]->setInaltimeCompleu(alegere);
                system("pause");
                break;
            }
            case 2:{
                system("cls");
                cout<<"Schimbati maneca? (0/1): ";
                cin>>alegere;
                if (alegere == 0)
                    break;
                randuriDeManechine[rand][pozitie - 1]->setManecaCompleu(!randuriDeManechine[rand][pozitie - 1]->getManecaCompleu());
                break;
            }
            case 3:{
                system("cls");
                cout<<"Schimbati lungimea? (0/1): ";
                cin>>alegere;
                if (alegere == 0)
                    break;
                randuriDeManechine[rand][pozitie - 1]->setPantaloniCompleu(!randuriDeManechine[rand][pozitie - 1]->getLungimeCompleu());
                break;
            }
            case 4:{
                system("cls");
                cout<<"Includeti/excludeti pantofii? (0/1): ";
                cin>>alegere;
                if (alegere == 0)
                    break;
                randuriDeManechine[rand][pozitie - 1]->setPapuciCompleu(!randuriDeManechine[rand][pozitie - 1]->getPapuciInclusiCompleu());
                if (randuriDeManechine[rand][pozitie - 1]->getPapuciInclusiCompleu()){
                    cout<<"Alegeti marimea (0/1): ";
                    cin>>alegere;
                    randuriDeManechine[rand][pozitie - 1]->setMarimePapuciCompleu(alegere);
                }
                break;
            }
            case 5:{
                system("cls");
                cout<<"Alegeti culoarea (g/a/v/r): ";
                char c; cin>>c;
                randuriDeManechine[rand][pozitie - 1]->setCuloareCompleu(c);
                break;
            }
        }
    } else {
        cout<<"1. Modifica palaria.\n";
        cout<<"2. Modifica tricoul.\n";
        cout<<"3. Modifica pantalonii.\n";
        cout<<"4. Modifica pantofii.\n";
        cout<<"Introduceti alegera: ";
        int alegere; cin>>alegere;
        switch (alegere) {
            case 1:{
                system("cls");
                cout<<"1. Introduceti/eliminati palarie.\n";
                cout<<"2. Modificati inaltimea.\n";
                cout<<"3. Modificati culoarea.\n";
                cout<<"Introduceti alegerea: ";
                cin>>alegere;
                switch(alegere) {
                    case 1:{
                        system("cls");
                        randuriDeManechine[rand][pozitie - 1]->setPalarie(!randuriDeManechine[rand][pozitie - 1]->getPalarie());
                        system("pause");
                        break;
                    }
                    case 2:{
                        system("cls");
                        cout<<"Alegeti inaltimea (1/2): ";
                        cin>>alegere;
                        randuriDeManechine[rand][pozitie - 1]->setInaltimePalarie(alegere);
                        system("pause");
                        break;
                    }
                    case 3:{
                        system("cls");
                        cout<<"Alegeti culoarea (g/a/v/r): ";
                        char c; cin>>c;
                        randuriDeManechine[rand][pozitie - 1]->setCuloarePalarie(c);
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 2:{
                system("cls");
                cout<<"1. Introduceti/eliminati tricou.\n";
                cout<<"2. Modificati maneca.\n";
                cout<<"3. Modificati culoarea.\n";
                cout<<"Introduceti alegerea: ";
                cin>>alegere;
                switch (alegere) {
                    case 1:{
                        system("cls");
                        randuriDeManechine[rand][pozitie - 1]->setTop(!randuriDeManechine[rand][pozitie - 1]->getTop());
                        system("pause");
                        break;
                    }
                    case 2:{
                        randuriDeManechine[rand][pozitie - 1]->setManecaTop(!randuriDeManechine[rand][pozitie - 1]->getManeca());
                        system("pause");
                        break;
                    }
                    case 3:{
                        system("cls");
                        cout<<"Alegeti culoarea (g/a/v/r): ";
                        char c; cin>>c;
                        randuriDeManechine[rand][pozitie - 1]->setCuloareTop(c);
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 3:{
                cout<<"1. Introduceti/eliminati pantaloni.\n";
                cout<<"2. Modificati lungimea.\n";
                cout<<"3. Modificati culoarea.\n";
                cout<<"Introduceti alegerea: ";
                cin>>alegere;
                switch (alegere){
                    case 1:{
                        system("cls");
                        randuriDeManechine[rand][pozitie - 1]->setBottom(!randuriDeManechine[rand][pozitie - 1]->getPantaloni());
                        system("pause");
                        break;
                    }
                    case 2:{
                        system("cls");
                        cout<<"Sunt scurti? (0/1): ";
                        cin>>alegere;
                        randuriDeManechine[rand][pozitie - 1]->setScrutiBottom(alegere);
                        system("pause");
                        break;
                    }
                    case 3:{
                        system("cls");
                        cout<<"Alegeti culoarea (g/a/v/r): ";
                        char c; cin>>c;
                        randuriDeManechine[rand][pozitie - 1]->setCuloareBottom(c);
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 4:{
                cout<<"1. Introduceti/eliminati pantofi.\n";
                cout<<"2. Modificati papucii.\n";
                cout<<"3. Modificati culoarea.\n";
                cout<<"Introduceti alegerea: ";
                cin>>alegere;
                switch (alegere){
                    case 1:{
                        system("cls");
                        randuriDeManechine[rand][pozitie - 1]->setShoes(!randuriDeManechine[rand][pozitie - 1]->getPapuci());
                        system("pause");
                        break;
                    }
                    case 2:{
                        system("cls");
                        cout<<"Sunt mari? (0/1): ";
                        cin>>alegere;
                        randuriDeManechine[rand][pozitie - 1]->setMarimePapuci(alegere);
                        system("pause");
                        break;
                    }
                    case 3:{
                        system("cls");
                        cout<<"Alegeti culoarea (g/a/v/r): ";
                        char c; cin>>c;
                        randuriDeManechine[rand][pozitie - 1]->setCuloarePapuci(c);
                        system("pause");
                        break;
                    }
                }
                break;
            }
        }
    }
}


void Magazin::deschide() {
    system("cls");
    cout<<"Bine ati venit!\n";
    system("pause");

    while (true){
        system("cls");
        cout<<"1. Insereaza.\n";
        cout<<"2. Modifica.\n";
        cout<<"3. Afiseaza.\n";
        cout<<"4. Sterge.\n";
        cout<<"5. Inchide.\n";
        cout<<"Introdu alegerea: ";
        int alegere;
        cin>>alegere;
        switch (alegere){
            case 1:{
                insereaza();
                break;
            }
            case 2:{
                modifica();
                break;
            }
            case 3:{
                afiseaza();
                break;
            }
            case 4:{
                sterge();
                break;
            }
            case 5:{
                exit(0);
                break;
            }
        }
    }
    }


int Magazin::nrOfInstance = 0;
Magazin* Magazin::obj = 0;

int main() {
    Magazin* magazin = magazin->getInstance();
    magazin->deschide();

    return 0;
}
