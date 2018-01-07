#ifndef TVECTORITEM_H
#define TVECTORITEM_H


class TVectorItem {
public:
    double Key;
    unsigned int Val;
    TVectorItem(double inpKey, unsigned int inpVal) {
        this->Key = inpKey;
        this->Val = inpVal;
    }

    bool operator <(TVectorItem r) {
        return this->Key < r.Key;
    }
};

#endif // TVECTORITEM_H
