// gcc -o tst main.c tst.c `pkg-config --cflags --libs eina efl elementary`
// gcc -g3 -O0 -o tst main.c tst.c `pkg-config --cflags --libs eina efl elementary`

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

static void
on_activated(void *obj, const Efl_Event *desc)
{
   printf("activated callback for %p\n", desc->object);
}

static void
on_disabled(void *obj, const Efl_Event *desc)
{
   printf("disabled callback for %p\n", desc->object);
}

EAPI_MAIN void
efl_main(void *data EINA_UNUSED, const Efl_Event *ev EINA_UNUSED)
{
   Tst *test;
   
   test = _tst_create();
   printf("Test obj is %p\n", test);

   tst_label_set(test, "Smelly");
   tst_size_set(test, 100);

   efl_event_callback_add(test, TST_EVENT_ACTIVATED, on_activated, NULL);
   efl_event_callback_add(test, TST_EVENT_DISABLED, on_disabled, NULL);

   tst_activate(test, 37, "Chickens");
   tst_disable(test, 99);

   efl_unref(test);
 
   efl_exit(0);
}
EFL_MAIN()

