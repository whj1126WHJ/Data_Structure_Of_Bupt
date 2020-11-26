//
// Created by AW on 2020/11/22.
//

#ifndef CLIONFILES_BM_H
#define CLIONFILES_BM_H

#endif //CLIONFILES_BM_H

#define XSIZE 200
typedef struct{
    char *ch;
    int length;
}HString;

//BM绠楁硶    锛圔oyer-Moore锛?   濂藉悗缂€鐩稿叧鍑芥暟
void preBmBc(HString Q, int m, int bmBc[]) {
    int i;
    for (i = 0; i <256; ++i)
        bmBc[i] = m;
    for (i = 0; i < m - 1; ++i)
        bmBc[Q.ch[i]] = m - i - 1;
}


void suffixes(HString Q, int m, int *suff) {
    int f, g, i;
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && Q.ch[g] == Q.ch[g + m - 1 - f])
                --g;
            suff[i] = f - g;
        }
    }
}

void preBmGs(HString Q, int m, int bmGs[]) {
    int i, j, suff[Q.length];
    suffixes(Q, m, suff);
    for (i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    for (i = m - 1; i >= 0; --i)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; ++j)
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
    for (i = 0; i <= m - 2; ++i)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}

int MAX(int i,int j)   //姹傛渶澶у€?
{
    if(i>j) return i;
    else return j;
}

void BM(HString Q, int m, HString S, int n) {
    int i, j, bmGs[Q.length], bmBc[256];
    preBmGs(Q, m, bmGs);
    preBmBc(Q, m, bmBc);
    j = 0;
    int num = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && Q.ch[i] == S.ch[i + j]; --i);
        if (i < 0) {
            printf("在位置%d发现匹配！\n",j+1);
            num++;
            j += bmGs[0];
        }
        else
            j += MAX(bmGs[i], bmBc[S.ch[i + j]] - m + 1 + i);
    }
}
