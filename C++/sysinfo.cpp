#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <sstream>
#endif

// Function to get the CPU model name
std::string GetCPUModel() {
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    std::string model_name = "Unknown";
    while (std::getline(cpuinfo, line)) {
        if (line.find("model name") != std::string::npos) {
            size_t colon_pos = line.find(":");
            if (colon_pos != std::string::npos) {
                model_name = line.substr(colon_pos + 2);
                break;
            }
        }
    }
    return model_name;
}

// Function to get memory usage in Linux
std::string GetMemoryUsage() {
    std::ifstream meminfo("/proc/meminfo");
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(meminfo, line)) {
        lines.push_back(line);
    }

    // Extract memory information
    std::string total_memory;
    std::string free_memory;

    for (const std::string& mem_line : lines) {
        if (mem_line.find("MemTotal") != std::string::npos) {
            total_memory = mem_line;
        } else if (mem_line.find("MemFree") != std::string::npos) {
            free_memory = mem_line;
        }
    }

    return total_memory + "\n" + free_memory;
}

int main() {
    // Get and print the operating system information
    std::string os_info;

#ifdef _WIN32
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((LPOSVERSIONINFO)&osvi);

    os_info = "Windows ";
    os_info += std::to_string(osvi.dwMajorVersion);
    os_info += ".";
    os_info += std::to_string(osvi.dwMinorVersion);
#elif __linux__
    struct utsname unameInfo;
    if (uname(&unameInfo) == 0) {
        os_info = unameInfo.sysname;
        os_info += " ";
        os_info += unameInfo.release;
    } else {
        os_info = "Linux (Unknown)";
    }
#else
    os_info = "Unknown OS";
#endif

    std::cout << "Operating System: " << os_info << std::endl;

    // Get and print system architecture
    std::string arch_info;

#ifdef _WIN32
    SYSTEM_INFO sys_info;
    GetNativeSystemInfo(&sys_info);
    if (sys_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) {
        arch_info = "64-bit";
    } else if (sys_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL) {
        arch_info = "32-bit";
    } else {
        arch_info = "Unknown Architecture";
    }
#elif __linux__
    arch_info = unameInfo.machine;
#else
    arch_info = "Unknown Architecture";
#endif

    std::cout << "System Architecture: " << arch_info << std::endl;

    // Get and print system uptime
#ifdef _WIN32
    DWORD dwTicks = GetTickCount();
    unsigned int days = dwTicks / (1000 * 60 * 60 * 24);
    unsigned int hours = (dwTicks / (1000 * 60 * 60)) % 24;
    unsigned int minutes = (dwTicks / (1000 * 60)) % 60;
    unsigned int seconds = (dwTicks / 1000) % 60;

    std::cout << "System Uptime: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << std::endl;
#elif __linux__
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        unsigned int days = info.uptime / (60 * 60 * 24);
        unsigned int hours = (info.uptime / (60 * 60)) % 24;
        unsigned int minutes = (info.uptime / 60) % 60;
        unsigned int seconds = info.uptime % 60;

        std::cout << "System Uptime: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << std::endl;
    }
#endif

    // Get and print CPU model
    std::string cpu_model = GetCPUModel();
    std::cout << "CPU Model: " << cpu_model << std::endl;

    // Get and print memory usage
#ifdef __linux__
    std::string memory_usage = GetMemoryUsage();
    std::cout << "Memory Info:\n" << memory_usage << std::endl;
#endif

    return 0;
}
