# PlatformIO pre-script: generate wildfire_node_config.h (the factory defaults
# variant.cpp installs) from the parent repo's node_config/main_node_config.yaml
# and secrets.yaml. The header goes in the build directory, out of git, since it
# holds the channel key. Uses the parent repo's .venv (PyYAML + meshtastic).

import os
import subprocess

Import("env")  # noqa: F821  (provided by PlatformIO)

repo = os.path.dirname(env.subst("$PROJECT_DIR"))  # noqa: F821
python = os.path.join(repo, ".venv", "bin", "python")
generator = os.path.join(repo, "node_config", "gen_firmware_defaults.py")
config = os.path.join(repo, "node_config", "main_node_config.yaml")
out_dir = os.path.join(env.subst("$BUILD_DIR"), "wildfire")  # noqa: F821

if not os.path.exists(python):
    print(f"error: {python} not found; run node_config/flash_wearable.sh or node_config/devboard_bootstrap.sh once to create it")
    env.Exit(1)  # noqa: F821
if subprocess.run([python, generator, config, os.path.join(out_dir, "wildfire_node_config.h")]).returncode:
    env.Exit(1)  # noqa: F821

env.Append(CPPPATH=[out_dir])  # noqa: F821
