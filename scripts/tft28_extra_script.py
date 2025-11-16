Import("env")
import shutil
import os

def copy_tft28_config(*args, **kwargs):
    if "TFT28_BOARD" in env.GetProjectOption("build_flags", ""):
        build_dir = env.GetBuildPath()
        libdeps_dir = os.path.join(build_dir, "..")  # .pio/libdeps/tft28/
        
        # === Copy User_Setup.h to TFT_eSPI ===
        src_setup = os.path.join(env.GetProjectDir(), "tft28_config", "User_Setup.h")
        dst_setup = os.path.join(libdeps_dir, "TFT_eSPI", "User_Setup.h")
        os.makedirs(os.path.dirname(dst_setup), exist_ok=True)
        shutil.copy(src_setup, dst_setup)
        print(f"[TFT28] Copied User_Setup.h → {dst_setup}")

        # === Copy lv_conf.h to ROOT of libdeps (NOT in lvgl/) ===
        src_lv = os.path.join(env.GetProjectDir(), "tft28_config", "lv_conf.h")
        dst_lv = os.path.join(libdeps_dir, "lv_conf.h")  # ← HERE!
        shutil.copy(src_lv, dst_lv)
        print(f"[TFT28] Copied lv_conf.h → {dst_lv}")

env.AddPreAction("buildprog", copy_tft28_config)