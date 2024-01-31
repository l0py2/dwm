static const unsigned int borderpx       = 2;
static const unsigned int snap           = 8;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft  = 0;
static const unsigned int systrayspacing = 2;
static const int systraypinningfailfirst = 1;
static const int showsystray             = 1;
static const int showbar                 = 1;
static const int topbar                  = 1;
static const char *fonts[]               = { "monospace:size=12" };

static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	{ "mpv", NULL, NULL, 1 << 4, 1, -1 },
};

static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
	{ "[]=", tile },
	{ "><>", NULL },
	{ "[M]", monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	{ MODKEY,           XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask, XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,           XK_b,      togglebar,      {0} },
	{ MODKEY,           XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,           XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,           XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,           XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,           XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,           XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,           XK_Return, zoom,           {0} },
	{ MODKEY,           XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask, XK_c,      killclient,     {0} },
	{ MODKEY,           XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,           XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,           XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,           XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask, XK_space,  togglefloating, {0} },
	{ MODKEY,           XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,           XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,           XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask, XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask, XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(            XK_1,                      0)
	TAGKEYS(            XK_2,                      1)
	TAGKEYS(            XK_3,                      2)
	TAGKEYS(            XK_4,                      3)
	TAGKEYS(            XK_5,                      4)
	TAGKEYS(            XK_6,                      5)
	TAGKEYS(            XK_7,                      6)
	TAGKEYS(            XK_8,                      7)
	TAGKEYS(            XK_9,                      8)
	{ MODKEY|ShiftMask, XK_q,      quit,           {0} },
};

static const Button buttons[] = {
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

