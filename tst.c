#define EFL_BETA_API_SUPPORT
#include <Eo.h>
#include "tst.eo.h"

typedef struct
{
   int size;
   char *name;
   Eina_Bool activated : 1;
   Eina_Bool disabled : 1;
} Tst_Data;

EOLIAN static void
_tst_label_set(Eo *obj, Tst_Data *pd, const char *name)
{
   printf("set label: %s -> %s\n", pd->name, name);
   if (pd->name) free(pd->name);
   pd->name = strdup(name);
}

EOLIAN static const char *
_tst_label_get(const Eo *obj, Tst_Data *pd)
{
   return pd->name;
}

EOLIAN static int
_tst_size_set(Eo *obj, Tst_Data *pd, int size)
{
   printf("size set %i -> %i\n", pd->size, size);
   pd->size = size;
   return EINA_TRUE;
}

EOLIAN static int
_tst_size_get(const Eo *obj, Tst_Data *pd)
{
   return pd->size;
}

EOLIAN static Eina_Bool
_tst_activate(Eo *obj, Tst_Data *pd, int number, const char *str)
{
   printf("activate! %i '%s'\n", number, str);
   pd->activated = EINA_TRUE;
   efl_event_callback_call(obj, TST_EVENT_ACTIVATED, NULL);
}

EOLIAN static void
_tst_disable(Eo *obj, Tst_Data *pd, int level)
{
   printf("disable\n");
   pd->disabled = EINA_TRUE;
   efl_event_callback_call(obj, TST_EVENT_DISABLED, NULL);
}

#include "tst.eo.c"
