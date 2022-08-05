#include "reclists.hpp"
#include "solutions.hpp"
#include<cstring>

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.


int numComponents(list p) //renamed to numComponents from numAtoms
{
    if( is_null(p) )
        return 0;
    return numComponents(cdr(p)) + 1;
}

int countAllAtoms(list p) //renamed to numAtoms from numComponents  total atoms
{
    if(is_null(p))
        return 0;
    if(is_atom(car(p)))
    {
        return 1 + countAllAtoms(cdr(p));
    }
    return countAllAtoms(car(p)) + countAllAtoms(cdr(p));
}

int numAtomsAtTopLevel(list p)
{
    if( is_null(p) )
    {
        return 0;
    }
    if(is_atom(car(p)))
    {
        return 1 + numAtomsAtTopLevel(cdr(p)) ;
    }
    return numAtomsAtTopLevel(cdr(p));
}

bool smember(list p, list q)
{
    if(is_null(p))
    {
        return false;
    }
    if(eq(car(p),q))
    {
        return true;
    }
    return smember(cdr(p), q);
}
bool member(list p, list q)
{
    /*p is an atom and q is an non-atomic list. member returns true if p appears anywhere in q.
(If p is not an atom or q is not a non-atomic list, the call is in error—you may detect this
or just bomb out.)

    */
    if(is_null(p))
    {
        return false;
    }
    if(!is_null(car(p)))
    {
        return member(cdr(p), q);
    }
    if(eq(car(p), q))
    {
        return true;
    }

    return false;
}
bool areEqual(list p, list q)
{
    if(is_null(p))
    {
        return true;
    }
    if(!eq(car(p), car(q)))
    {
        return false;
    }
    return areEqual(cdr(p),cdr(q));

}
list append(list p, list q)
{
    if( is_null(p))
        return q;
    return cons(car(p), append(cdr(p),q));

}

list sreverse(list p) 
{
    if(is_null(p) or is_atom(p)) return p;
    return append(sreverse(cdr(p)), cons(car(p), null()));

}

bool is_lat(list p) 
{
/*is_lat takes a non-atomic (a list that is not an atom) list and returns true if the list is a
list (potentially empty) of atoms. (It can bomb out if p is an atom, or you may check for
errors and report them if you prefer.) For example
*/
    if(is_null(p))
    {
        return true;
    }
    if(!is_atom(car(p)))
    {
        return false;
    }
    return is_lat(cdr(p));

}

list last(list p)
{
/*last returns the last element, ln, of a non-atomic, non-empty list. (Do this without using
reverse.) Note that last of (a b c) is c, not (c).
*/
    if(is_null(p)) //end of list
    {
        return null();
    }
    if(is_null(cdr(p)))
    {
        return append(cons(car(p), null()), null());
    }
    return last(cdr(p));

}

list list_pair(list p, list q)
{
/* list_pair takes two lists of atoms of the same length (you may check for an error if you
like—or just bomb out) and returns a list that consists of lists of two atoms each, which
are the corresponding atoms paired up. For example:
*/
    if(is_null(p))
    {
        return null();
    }
    if(is_atom(car(p)) and is_atom(car(q)))
    {
        //return append(car(p), car(q));
    }
    //return list_pair(cdr(p), cdr(q));
    list pair = append(append(cons(car(p), null()), null()),append(cons(car(q), null()), null())); //GETS PAIR
    return cons(append(list_pair(cdr(p), cdr(q)), pair), null()); //combines pairs

}

list firsts(list p)
{
/*firsts takes as an argument a list whose elements are lists of atoms and returns a list
which contains the first element from each of the lists. For example:
*/
    if(is_null(p))
    {
        return null();
    }
    list first = append(cons(car(car(p)), null()), null());
    return append(firsts(cdr(p)), first);
    //return first;

}

list flat(list p)
{
    /*flat takes a non-atomic list and returns a list which is the original list with the parenthesis
removed (except for the outer set). For the lists in (3) of the definition, flat yields
    */
    if(is_null(p))
    {
        return null();
    }
    if(is_atom(car(p))) //below is an atom combine and continure right
    {
        return cons(car(p), flat(cdr(p)));
    }
    return append(flat(car(p)), flat(cdr(p)));

}

bool two_the_same(list p, list q)
{
    /*
    two_the_same takes two non-atomic recursive lists and returns true if p and q contain at
least one atom in common.
    */
    if(is_null(p) or is_null(q))
    {
        return false;
    }
    if(member(car(p), q)) //if it exist in the list
    {
        return true;
    }
    if(!is_atom(car(p))) //isnt in the list, isnt null, isnt a atom
    {
        return two_the_same(car(p), q); //go down and check
    }
    return two_the_same(cdr(p), q); //go right and check

}

bool equal(list p, list q)
{
    /*equal takes two arbitrary recursive lists and determines if they are identical, that is the
parentheses are all in the same place and the atoms agree as to place and name. This is
an extension of eq.
    */
    if(is_null(p) or is_null(q))
    {
        return is_null(p) and is_null(q);
    }
    if(is_null(p) and is_null(q))
    {
        return is_null(p) and is_null(q);
    }
    if(is_atom(car(p)) and !eq(car(p), car(q)))
    {
        return false;
    }
    if(eq(car(p), car(q)) and is_atom(car(q)))
    {
        return equal(cdr(p), cdr(q));
    }

    return equal(cdr(p),cdr(q)) and equal(cdr(p), cdr(q));
    
}

list total_reverse(list p)
{
    /*This function takes a recursive list and returns its mirror image. It is the extension of
reverse that reverses the list and each sub-list, recursively, unto the nth generation.
    */
    if(is_null(p))
    {
        return null();
    }
    if(!is_atom(car(p))) //isnt null and isnt a atom combine right and down to get into next list
    {
        return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
    }
    return append(total_reverse(cdr(p)), cons(car(p), null())); //within then list combine from start

}

list shape(list p)
{
    /* shape takes a non-atomic recursive list and returns a recursive list that consists of only
the parentheses in the original.
    */
    //Found out accidently when creating Flat, should work most of time
    if(is_null(p))
    {
        return null();
    }

    else if(!is_atom(car(p))) //isnt an atom and isnt null so append cons shape of right and down of list //ELSE IF IS REQUIRED TO WORK UNSURE WHY
    {
        return append(cons(shape(car(p)), null()), shape(cdr(p)));
    }
    return shape(cdr(p));

}

list intersection(list p, list q)
{
    /* p and q are lists of atoms with no atom appearing twice in p and no atom appearing twice
in q. p and q represent sets. intersection forms their intersection. (The empty list
represents the empty set.)
    */
    if(is_null(p) or is_null(q))
    {
        return null();
    }
    if (member(car(p), q)) //if its a memeber combine down and right
    {
        return cons(car(p), intersection(cdr(p), q));
    }
    return intersection(cdr(p), cdr(q));

}

list list_union(list p, list q)
{
    /*list_union forms the set which is their union—remember if p and q have an atom in
common then this atom should only appear once in the union.
    */

    if(is_null(p) or is_null(q))
    {
        if(is_null(q))
        {
            return append(null(), p);
        }
        return append(null(), q);
    }

    if(!member(car(p), q))
    {
        return cons(car(p), list_union(cdr(p), q));
    }
    if(member(car(p),q))
    {
        return append(list_union(cdr(p), q), null());
    }
}

list permute(list p) //HOOWWWWWW
{
    if(is_null(p))
    {
        return null();
    }
    //for(int i = 0; i <= r; i++)
    {
        


    }
    return p; //TEMP
}