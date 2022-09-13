#ifndef _TST_EO_H_
#define _TST_EO_H_

#ifndef _TST_EO_CLASS_TYPE
#define _TST_EO_CLASS_TYPE

typedef Eo Tst;

#endif

#ifndef _TST_EO_TYPES
#define _TST_EO_TYPES


#endif
#define TST_CLASS tst_class_get()

EWAPI const Efl_Class *tst_class_get(void) EINA_CONST;

EOAPI void tst_label_set(Eo *obj, const char *name);

EOAPI const char *tst_label_get(const Eo *obj);

EOAPI int tst_size_set(Eo *obj, int size);

EOAPI int tst_size_get(const Eo *obj);

EOAPI Eina_Bool tst_activate(Eo *obj, int number, const char *str);

EOAPI void tst_disable(Eo *obj, int level);

EWAPI extern const Efl_Event_Description _TST_EVENT_ACTIVATED;

/** When the tst object has been activated
 *
 * @ingroup Tst
 */
#define TST_EVENT_ACTIVATED (&(_TST_EVENT_ACTIVATED))

EWAPI extern const Efl_Event_Description _TST_EVENT_DISABLED;

/** When the tst object has been disabled
 *
 * @ingroup Tst
 */
#define TST_EVENT_DISABLED (&(_TST_EVENT_DISABLED))

#endif
