EWAPI const Efl_Event_Description _TST_EVENT_ACTIVATED =
   EFL_EVENT_DESCRIPTION("activated");
EWAPI const Efl_Event_Description _TST_EVENT_DISABLED =
   EFL_EVENT_DESCRIPTION("disabled");

void _tst_label_set(Eo *obj, Tst_Data *pd, const char *name);


static Eina_Error
__eolian_tst_label_set_reflect(Eo *obj, Eina_Value val)
{
   Eina_Error r = 0;   const char *cval;
   if (!eina_value_string_convert(&val, &cval))
      {
         r = EINA_ERROR_VALUE_FAILED;
         goto end;
      }
   tst_label_set(obj, cval);
 end:
   eina_value_flush(&val);
   return r;
}

EOAPI EFL_VOID_FUNC_BODYV(tst_label_set, EFL_FUNC_CALL(name), const char *name);

const char *_tst_label_get(const Eo *obj, Tst_Data *pd);


static Eina_Value
__eolian_tst_label_get_reflect(const Eo *obj)
{
   const char *val = tst_label_get(obj);
   return eina_value_string_init(val);
}

EOAPI EFL_FUNC_BODY_CONST(tst_label_get, const char *, NULL);

int _tst_size_set(Eo *obj, Tst_Data *pd, int size);


static Eina_Error
__eolian_tst_size_set_reflect(Eo *obj, Eina_Value val)
{
   Eina_Error r = 0;   int cval;
   if (!eina_value_int_convert(&val, &cval))
      {
         r = EINA_ERROR_VALUE_FAILED;
         goto end;
      }
   tst_size_set(obj, cval);
 end:
   eina_value_flush(&val);
   return r;
}

EOAPI EFL_FUNC_BODYV(tst_size_set, int, 0, EFL_FUNC_CALL(size), int size);

int _tst_size_get(const Eo *obj, Tst_Data *pd);


static Eina_Value
__eolian_tst_size_get_reflect(const Eo *obj)
{
   int val = tst_size_get(obj);
   return eina_value_int_init(val);
}

EOAPI EFL_FUNC_BODY_CONST(tst_size_get, int, 0);

Eina_Bool _tst_activate(Eo *obj, Tst_Data *pd, int number, const char *str);

EOAPI EFL_FUNC_BODYV(tst_activate, Eina_Bool, 0, EFL_FUNC_CALL(number, str), int number, const char *str);

void _tst_disable(Eo *obj, Tst_Data *pd, int level);

EOAPI EFL_VOID_FUNC_BODYV(tst_disable, EFL_FUNC_CALL(level), int level);

static Eina_Bool
_tst_class_initializer(Efl_Class *klass)
{
   const Efl_Object_Ops *opsp = NULL;

   const Efl_Object_Property_Reflection_Ops *ropsp = NULL;

#ifndef TST_EXTRA_OPS
#define TST_EXTRA_OPS
#endif

   EFL_OPS_DEFINE(ops,
      EFL_OBJECT_OP_FUNC(tst_label_set, _tst_label_set),
      EFL_OBJECT_OP_FUNC(tst_label_get, _tst_label_get),
      EFL_OBJECT_OP_FUNC(tst_size_set, _tst_size_set),
      EFL_OBJECT_OP_FUNC(tst_size_get, _tst_size_get),
      EFL_OBJECT_OP_FUNC(tst_activate, _tst_activate),
      EFL_OBJECT_OP_FUNC(tst_disable, _tst_disable),
      TST_EXTRA_OPS
   );
   opsp = &ops;

   static const Efl_Object_Property_Reflection refl_table[] = {
      {"label", __eolian_tst_label_set_reflect, __eolian_tst_label_get_reflect},
      {"size", __eolian_tst_size_set_reflect, __eolian_tst_size_get_reflect},
   };
   static const Efl_Object_Property_Reflection_Ops rops = {
      refl_table, EINA_C_ARRAY_LENGTH(refl_table)
   };
   ropsp = &rops;

   return efl_class_functions_set(klass, opsp, ropsp);
}

static const Efl_Class_Description _tst_class_desc = {
   EO_VERSION,
   "Tst",
   EFL_CLASS_TYPE_REGULAR,
   sizeof(Tst_Data),
   _tst_class_initializer,
   _tst_class_constructor,
   _tst_class_destructor
};

EFL_DEFINE_CLASS(tst_class_get, &_tst_class_desc, EFL_OBJECT_CLASS, NULL);
