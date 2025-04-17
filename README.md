# Projekt - Bipartitný graf

Náš kód využíva techniku prehľadávania BFS na zisťovanie, či je daný graf bipartitný. Postupne prechádzame každý vrchol grafu a pokúšame sa ich zaradiť do dvoch oddelených skupín (označených 0 a 1). Počas prehľadávania kontrolujeme, či medzi vrcholmi v rovnakej skupine neexistuje hrana. Ak nájdeme dva susedné vrcholy zaradené do rovnakej skupiny, graf nie je bipartitný. Naopak, ak sa nám podarí zaradiť všetky vrcholy tak, že každá hrana spája vrcholy z rôznych skupín, môžeme potvrdiť, že graf je bipartitný.

### Usage:
```
g++ main.cpp -o main.exe
main.exe input.txt
```