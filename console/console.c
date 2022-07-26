#include "console.h"
#include "../drivers/display.h"

const char *prompt = "[west-shell (v.1)] :-# ";

void banner() {
  kprint("__          __       _   _  __               \n");
  kprint("\\ \\        / /      | | | |/ /               \n");
  kprint("  \\ \\  /\\  / /__  ___| |_| ' / ___ _ __ _ __\n");
  kprint("   \\ \\/  \\/ / _ \\/ __| __|  < / _ \\ '__| '_ \\ \n");
  kprint("    \\  /\\  /  __/\\__ \\ |_| . \\  __/ |  | | | |\n");
  kprint("     \\/  \\/ \\___||___/\\__|_|\\_\\___|_|  |_| |_|\n\n");
}

void set_prompt() {
  kprint(prompt);
}

void init_console() {
  clear();
  banner();
  set_prompt();
}
