#include <sys/types.h>

#include <cstdint>

class breakpoint {
 public:
  breakpoint(pid_t pid, std::intptr_t addr);

  void enable();
  void disable();

  auto is_enabled() const -> bool { return m_enabled; }
  auto get_address() const -> std::intptr_t { return m_addr; }

 private:
  pid_t m_pid;
  std::intptr_t m_addr;
  bool m_enabled;
  uint8_t m_saved_data;
};