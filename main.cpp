#include <dllentry.h>
#include <log.h>
#include "settings.h"
#include "playerdb.h"

DEF_LOGGER("SampleMod");
DEFAULT_SETTINGS(settings);

// PS: Reserved for compatibility purposes
// If it is not necessary, keep both functions empty
// Initialization can be done in the PreInit function
// Incorrect use of this function may cause a crash
void dllenter() {}
void dllexit() {}

void PreInit() {
  LOGV("pre init");
  // You can use the event system to receive and process events
  // The following is an example
  Mod::PlayerDatabase::GetInstance().AddListener(SIG("joined"), [](Mod::PlayerEntry const &entry) {
    LOGV("joined name: %s, xuid: %d") % entry.name % entry.xuid;
  });
  Mod::PlayerDatabase::GetInstance().AddListener(
      SIG("left"), [](Mod::PlayerEntry const &entry) { LOGV("left name: %s, xuid: %d") % entry.name % entry.xuid; });
}
void PostInit() { LOGV("post init"); }
