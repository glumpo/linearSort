#ifndef TVECTORITEM_H
#define TVECTORITEM_H


class TVectorItem {
public:
    double Key;
    unsigned long long Val;
    TVectorItem(double inpKey, unsigned long long inpVal) {
        this->Key = inpKey;
        this->Val = inpVal;
    }

    bool operator <(TVectorItem r) {
        return this->Key < r.Key;
    }

    bool operator >(TVectorItem r) {
        return this->Key > r.Key;
    }
};

#endif // TVECTORITEM_H
