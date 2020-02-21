#include <dllentry.h>
#include <log.h>
#include "settings.h"
#include "playerdb.h"

Settings settings;

DEF_LOGGER("SampleMod");
DEFAULT_SETTINGS(settings);

void dllenter() { LOGV("ENTER"); }
void dllexit() { std::cerr << "EXIT (PS: Don't use LOG function here, it will cause crash)" << std::endl; }

void PreInit() {
  LOGV("pre init");
  Mod::PlayerDatabase::GetInstance().AddListener(SIG("joined"), [](Mod::PlayerEntry const &entry) {
    LOGV("joined name: %s, xuid: %d") % entry.name % entry.xuid;
  });
  Mod::PlayerDatabase::GetInstance().AddListener(
      SIG("left"), [](Mod::PlayerEntry const &entry) { LOGV("left name: %s, xuid: %d") % entry.name % entry.xuid; });
}
void PostInit() { LOGV("post init"); }