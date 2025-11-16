SET(SOURCES components/ui_comp_buttonnav.c
    components/ui_comp.c
    screens/ui_Home.c
    screens/ui_Setup.c
    screens/ui_Trial.c
    screens/ui_Result.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c)

add_library(ui ${SOURCES})
