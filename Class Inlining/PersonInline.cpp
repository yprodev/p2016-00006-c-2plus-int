#include "PersonInline.h"

PersonInline::PersonInline()
{
    // construction code
}
PersonInline::~PersonInline()
{
    // destruction code
}
/*
    5d. Those are the three ways of declaring inline functions within classes. At this point
    we should probably also point out that inline is NOT a command to compiler. It is NOT
    imperative. When the compiler finds an inline request, eighter excplicit or implicit,
    it would generaly do a cost benefit analysis on the function concerned. If it consider
    benefit inlining the function it will do so.

    Certain functions can not be inlined. Functions that can not be inlined are:
        1. functions which call themselves or recursive functions
        2. functions which are called via a pointer to a function
        3. functions which the compiler regards too complicated, too large or have no benefit
           in inlining

*/
void inline PersonInline::ExcplicitInlineUsePersonAgain()
{
    // use person again
}
