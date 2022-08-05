#ifndef __MYSOLUTION_HPP
#define __MYSOLUTION_HPP

#include<iostream>
#include"reclists.hpp"
#include<cstring>

int countAllAtoms(list p);

int numComponents(list p);

int numAtomsAtTopLevel(list p);

bool smember(list p, list q); // q is an atom

bool member(list p, list q);

bool areEqual(list p, list q);
// p & q are list of atoms
// p & q have same amt of atoms
//function trues true if the atoms
//in p are in the same order as q
// p {a b c d} and q [ a b c d] true
// p {a b c d} and q [a c b d] false

list repeatAtom(list p, int n);
//p is an atom
// repeatAtom builds a list that contains n copies of p

//repeatAtom(a, 0) returns()
//repeatAtom(a, 5) returns(a, a, a, a, a)

list append(list p, list q);
list sreverse(list p);
//a b c
//c b a
// (a (b c), (e, f) g)
//(g (ef) (bc a))
bool is_lat(list p);
list last(list p);
list list_pair(list p, list q);
list firsts(list p);
list flat(list p);
bool two_the_same(list p, list q);
bool equal(list p, list q);
list total_reverse(list p);

list shape(list p);
list intersection(list p, list q);
list list_union(list p, list q);
list permute(list p);
#endif
