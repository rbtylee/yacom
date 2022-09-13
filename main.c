// gcc -o tst main.c tst.c `pkg-config --cflags --libs eina efl elementary`
// eolian_gen -gchi tst.eo
#define EFL_BETA_API_SUPPORT

#include <Eina.h>
#include <Efl_Core.h>
#include "tst.eo.h"

Tst *
_tst_create()
{
   Tst *test;
 
   test = efl_new(TST_CLASS,
                  efl_name_set(efl_added, "tst"));
 
   return test;
}


EAPI_MAIN void
efl_main(void *data EINA_UNUSED, const Efl_Event *ev EINA_UNUSED)
{
   Tst *test;
 
   test = _tst_create();
   tst_label_set(test, "Smelly"),
   tst_size_set(test, 100),
    
   efl_unref(test);
 
   efl_exit(0);
}
EFL_MAIN()

