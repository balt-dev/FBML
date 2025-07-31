#include <stdint.h>
#include <windows.h>

static HMODULE g_original_dll;

typedef struct lua_State {
  char dummy;
} lua_State;
typedef int (*lua_CFunction)(lua_State *L);
typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);
typedef double lua_Number;
typedef long long lua_Integer;
typedef unsigned int lua_Unsigned;
typedef const char *(*lua_Reader)(lua_State *L, void *ud, size_t *sz);
typedef int (*lua_Writer)(lua_State *L, const void *p, size_t sz, void *ud);
typedef void *(*lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize);
typedef struct lua_Debug {
  char dummy;
} lua_Debug;
typedef void (*lua_Hook)(lua_State *L, lua_Debug *ar);
typedef struct luaL_Buffer {
  char dummy;
} luaL_Buffer;
typedef struct luaL_Stream {
  char dummy;
} luaL_Stream;
typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;

#define REDEF(name, ret, args, vars)                                           \
  typedef ret(*PROXY_##name##_FUNC) args;                                      \
  __declspec(dllexport) ret name args {                                        \
    static PROXY_##name##_FUNC orig = NULL;                                    \
    orig = orig ? orig                                                         \
                : (PROXY_##name##_FUNC)GetProcAddress(g_original_dll, #name);  \
    return orig vars;                                                          \
  }

REDEF(lua_close, void, (lua_State * L), (L));
REDEF(lua_newthread, lua_State *, (lua_State * L), (L));
REDEF(lua_atpanic, lua_CFunction, (lua_State * L, lua_CFunction panicf),
      (L, panicf));
REDEF(lua_version, const lua_Number *, (lua_State * L), (L));
REDEF(lua_absindex, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_gettop, int, (lua_State * L), (L));
REDEF(lua_settop, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_pushvalue, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_remove, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_insert, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_replace, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_copy, void, (lua_State * L, int fromidx, int toidx),
      (L, fromidx, toidx));
REDEF(lua_checkstack, int, (lua_State * L, int sz), (L, sz));
REDEF(lua_xmove, void, (lua_State * from, lua_State *to, int n), (from, to, n));
REDEF(lua_isnumber, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_isstring, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_iscfunction, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_isuserdata, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_type, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_typename, const char *, (lua_State * L, int tp), (L, tp));
REDEF(lua_tonumberx, lua_Number, (lua_State * L, int idx, int *isnum),
      (L, idx, isnum));
REDEF(lua_tointegerx, lua_Integer, (lua_State * L, int idx, int *isnum),
      (L, idx, isnum));
REDEF(lua_tounsignedx, lua_Unsigned, (lua_State * L, int idx, int *isnum),
      (L, idx, isnum));
REDEF(lua_toboolean, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_tolstring, const char *, (lua_State * L, int idx, size_t *len),
      (L, idx, len));
REDEF(lua_rawlen, size_t, (lua_State * L, int idx), (L, idx));
REDEF(lua_tocfunction, lua_CFunction, (lua_State * L, int idx), (L, idx));
REDEF(lua_touserdata, void *, (lua_State * L, int idx), (L, idx));
REDEF(lua_tothread, lua_State *, (lua_State * L, int idx), (L, idx));
REDEF(lua_topointer, const void *, (lua_State * L, int idx), (L, idx));
REDEF(lua_arith, void, (lua_State * L, int op), (L, op));
REDEF(lua_rawequal, int, (lua_State * L, int idx1, int idx2), (L, idx1, idx2));
REDEF(lua_compare, int, (lua_State * L, int idx1, int idx2, int op),
      (L, idx1, idx2, op));
REDEF(lua_pushnil, void, (lua_State * L), (L));
REDEF(lua_pushnumber, void, (lua_State * L, lua_Number n), (L, n));
REDEF(lua_pushinteger, void, (lua_State * L, lua_Integer n), (L, n));
REDEF(lua_pushunsigned, void, (lua_State * L, lua_Unsigned n), (L, n));
REDEF(lua_pushlstring, const char *, (lua_State * L, const char *s, size_t l),
      (L, s, l));
REDEF(lua_pushstring, const char *, (lua_State * L, const char *s), (L, s));
REDEF(lua_pushvfstring, const char *,
      (lua_State * L, const char *fmt, va_list argp), (L, fmt, argp));
REDEF(lua_pushcclosure, void, (lua_State * L, lua_CFunction fn, int n),
      (L, fn, n));
REDEF(lua_pushboolean, void, (lua_State * L, int b), (L, b));
REDEF(lua_pushlightuserdata, void, (lua_State * L, void *p), (L, p));
REDEF(lua_pushthread, int, (lua_State * L), (L));
REDEF(lua_getglobal, void, (lua_State * L, const char *var), (L, var));
REDEF(lua_gettable, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_getfield, void, (lua_State * L, int idx, const char *k), (L, idx, k));
REDEF(lua_rawget, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_rawgeti, void, (lua_State * L, int idx, int n), (L, idx, n));
REDEF(lua_rawgetp, void, (lua_State * L, int idx, const void *p), (L, idx, p));
REDEF(lua_createtable, void, (lua_State * L, int narr, int nrec),
      (L, narr, nrec));
REDEF(lua_newuserdata, void *, (lua_State * L, size_t sz), (L, sz));
REDEF(lua_getmetatable, int, (lua_State * L, int objindex), (L, objindex));
REDEF(lua_getuservalue, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_setglobal, void, (lua_State * L, const char *var), (L, var));
REDEF(lua_settable, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_setfield, void, (lua_State * L, int idx, const char *k), (L, idx, k));
REDEF(lua_rawset, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_rawseti, void, (lua_State * L, int idx, int n), (L, idx, n));
REDEF(lua_rawsetp, void, (lua_State * L, int idx, const void *p), (L, idx, p));
REDEF(lua_setmetatable, int, (lua_State * L, int objindex), (L, objindex));
REDEF(lua_setuservalue, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_callk, void,
      (lua_State * L, int nargs, int nresults, int ctx, lua_CFunction k),
      (L, nargs, nresults, ctx, k));
REDEF(lua_getctx, int, (lua_State * L, int *ctx), (L, ctx));
REDEF(lua_pcallk, int,
      (lua_State * L, int nargs, int nresults, int errfunc, int ctx,
       lua_CFunction k),
      (L, nargs, nresults, errfunc, ctx, k));
REDEF(lua_load, int,
      (lua_State * L, lua_Reader reader, void *dt, const char *mode),
      (L, reader, dt, mode));
REDEF(lua_dump, int, (lua_State * L, lua_Writer writer, void *data),
      (L, writer, data));
REDEF(lua_yieldk, int, (lua_State * L, int nresults, int ctx, lua_CFunction k),
      (L, nresults, ctx, k));
REDEF(lua_resume, int, (lua_State * L, lua_State *from, int narg),
      (L, from, narg));
REDEF(lua_status, int, (lua_State * L), (L));
REDEF(lua_gc, int, (lua_State * L, int what, int data), (L, what, data));
REDEF(lua_error, int, (lua_State * L), (L));
REDEF(lua_next, int, (lua_State * L, int idx), (L, idx));
REDEF(lua_concat, void, (lua_State * L, int n), (L, n));
REDEF(lua_len, void, (lua_State * L, int idx), (L, idx));
REDEF(lua_getallocf, lua_Alloc, (lua_State * L, void **ud), (L, ud));
REDEF(lua_setallocf, void, (lua_State * L, lua_Alloc f, void *ud), (L, f, ud));
REDEF(lua_getstack, int, (lua_State * L, int level, lua_Debug *ar),
      (L, level, ar));
REDEF(lua_getinfo, int, (lua_State * L, const char *what, lua_Debug *ar),
      (L, what, ar));
REDEF(lua_getlocal, const char *, (lua_State * L, const lua_Debug *ar, int n),
      (L, ar, n));
REDEF(lua_setlocal, const char *, (lua_State * L, const lua_Debug *ar, int n),
      (L, ar, n));
REDEF(lua_getupvalue, const char *, (lua_State * L, int funcindex, int n),
      (L, funcindex, n));
REDEF(lua_setupvalue, const char *, (lua_State * L, int funcindex, int n),
      (L, funcindex, n));
REDEF(lua_upvalueid, void *, (lua_State * L, int fidx, int n), (L, fidx, n));
REDEF(lua_upvaluejoin, void,
      (lua_State * L, int fidx1, int n1, int fidx2, int n2),
      (L, fidx1, n1, fidx2, n2));
REDEF(lua_sethook, int, (lua_State * L, lua_Hook func, int mask, int count),
      (L, func, mask, count));
REDEF(lua_gethook, lua_Hook, (lua_State * L), (L));
REDEF(lua_gethookmask, int, (lua_State * L), (L));
REDEF(lua_gethookcount, int, (lua_State * L), (L));
REDEF(luaopen_base, int, (lua_State * L), (L));
REDEF(luaopen_coroutine, int, (lua_State * L), (L));
REDEF(luaopen_table, int, (lua_State * L), (L));
REDEF(luaopen_io, int, (lua_State * L), (L));
REDEF(luaopen_os, int, (lua_State * L), (L));
REDEF(luaopen_string, int, (lua_State * L), (L));
REDEF(luaopen_bit32, int, (lua_State * L), (L));
REDEF(luaopen_math, int, (lua_State * L), (L));
REDEF(luaopen_debug, int, (lua_State * L), (L));
REDEF(luaopen_package, int, (lua_State * L), (L));
REDEF(luaL_newstate, lua_State *, (void), ());
REDEF(luaL_checkversion_, void, (lua_State * L, lua_Number ver), (L, ver));
REDEF(luaL_getmetafield, int, (lua_State * L, int obj, const char *e),
      (L, obj, e));
REDEF(luaL_callmeta, int, (lua_State * L, int obj, const char *e), (L, obj, e));
REDEF(luaL_tolstring, const char *, (lua_State * L, int idx, size_t *len),
      (L, idx, len));
REDEF(luaL_argerror, int, (lua_State * L, int numarg, const char *extramsg),
      (L, numarg, extramsg));
REDEF(luaL_checklstring, const char *, (lua_State * L, int numArg, size_t *l),
      (L, numArg, l));
REDEF(luaL_optlstring, const char *,
      (lua_State * L, int numArg, const char *def, size_t *l),
      (L, numArg, def, l));
REDEF(luaL_checknumber, lua_Number, (lua_State * L, int numArg), (L, numArg));
REDEF(luaL_optnumber, lua_Number, (lua_State * L, int nArg, lua_Number def),
      (L, nArg, def));
REDEF(luaL_checkinteger, lua_Integer, (lua_State * L, int numArg), (L, numArg));
REDEF(luaL_optinteger, lua_Integer, (lua_State * L, int nArg, lua_Integer def),
      (L, nArg, def));
REDEF(luaL_checkunsigned, lua_Unsigned, (lua_State * L, int numArg),
      (L, numArg));
REDEF(luaL_optunsigned, lua_Unsigned,
      (lua_State * L, int numArg, lua_Unsigned def), (L, numArg, def));
REDEF(luaL_checkstack, void, (lua_State * L, int sz, const char *msg),
      (L, sz, msg));
REDEF(luaL_checktype, void, (lua_State * L, int narg, int t), (L, narg, t));
REDEF(luaL_checkany, void, (lua_State * L, int narg), (L, narg));
REDEF(luaL_newmetatable, int, (lua_State * L, const char *tname), (L, tname));
REDEF(luaL_setmetatable, void, (lua_State * L, const char *tname), (L, tname));
REDEF(luaL_testudata, void *, (lua_State * L, int ud, const char *tname),
      (L, ud, tname));
REDEF(luaL_checkudata, void *, (lua_State * L, int ud, const char *tname),
      (L, ud, tname));
REDEF(luaL_where, void, (lua_State * L, int lvl), (L, lvl));
REDEF(luaL_checkoption, int,
      (lua_State * L, int narg, const char *def, const char *const lst[]),
      (L, narg, def, lst));
REDEF(luaL_fileresult, int, (lua_State * L, int stat, const char *fname),
      (L, stat, fname));
REDEF(luaL_execresult, int, (lua_State * L, int stat), (L, stat));
REDEF(luaL_ref, int, (lua_State * L, int t), (L, t));
REDEF(luaL_unref, void, (lua_State * L, int t, int ref), (L, t, ref));
REDEF(luaL_loadfilex, int,
      (lua_State * L, const char *filename, const char *mode),
      (L, filename, mode));
REDEF(luaL_loadbufferx, int,
      (lua_State * L, const char *buff, size_t sz, const char *name,
       const char *mode),
      (L, buff, sz, name, mode));
REDEF(luaL_loadstring, int, (lua_State * L, const char *s), (L, s));
REDEF(luaL_len, int, (lua_State * L, int idx), (L, idx));
REDEF(luaL_gsub, const char *,
      (lua_State * L, const char *s, const char *p, const char *r),
      (L, s, p, r));
REDEF(luaL_setfuncs, void, (lua_State * L, const luaL_Reg *l, int nup),
      (L, l, nup));
REDEF(luaL_getsubtable, int, (lua_State * L, int idx, const char *fname),
      (L, idx, fname));
REDEF(luaL_traceback, void,
      (lua_State * L, lua_State *L1, const char *msg, int level),
      (L, L1, msg, level));
REDEF(luaL_requiref, void,
      (lua_State * L, const char *modname, lua_CFunction openf, int glb),
      (L, modname, openf, glb));
REDEF(luaL_buffinit, void, (lua_State * L, luaL_Buffer *B), (L, B));
REDEF(luaL_prepbuffsize, char *, (luaL_Buffer * B, size_t sz), (B, sz));
REDEF(luaL_addlstring, void, (luaL_Buffer * B, const char *s, size_t l),
      (B, s, l));
REDEF(luaL_addstring, void, (luaL_Buffer * B, const char *s), (B, s));
REDEF(luaL_addvalue, void, (luaL_Buffer * B), (B));
REDEF(luaL_pushresult, void, (luaL_Buffer * B), (B));
REDEF(luaL_pushresultsize, void, (luaL_Buffer * B, size_t sz), (B, sz));
REDEF(luaL_buffinitsize, char *, (lua_State * L, luaL_Buffer *B, size_t sz),
      (L, B, sz));
REDEF(luaL_pushmodule, void, (lua_State * L, const char *modname, int sizehint),
      (L, modname, sizehint));
REDEF(luaL_openlib, void,
      (lua_State * L, const char *libname, const luaL_Reg *l, int nup),
      (L, libname, l, nup))

// Fuck it

extern const char *lua_pushfstring(lua_State *L, const char *fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  return lua_pushvfstring(L, fmt, argp);
}

extern int luaL_error(lua_State *L, const char *fmt, ...) {
  va_list argp;
  va_start(argp, fmt);
  luaL_where(L, 1);
  lua_pushvfstring(L, fmt, argp);
  va_end(argp);
  lua_concat(L, 2);
  return lua_error(L);
}
