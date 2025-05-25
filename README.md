# Keylogger-Analysis

# 🛡️ Snake Keylogger Malware Analysis

An in-depth static and dynamic analysis of the Snake Keylogger malware sample. This project dissects its infection vectors, operational behavior, evasion techniques, and proposes effective mitigation strategies. The analysis was conducted in a secure, sandboxed environment using industry-standard tools and virtual machines.

---

## 📚 Table of Contents

1. [Introduction](#introduction)
2. [Static Analysis](#static-analysis)
3. [Dynamic Analysis](#dynamic-analysis)
4. [Mitigation Strategies](#mitigation-strategies)
5. [Tools Used](#tools-used)
6. [Conclusion](#conclusion)

---

## 🧠 Introduction

**Snake Keylogger** is an advanced malware strain known for stealing sensitive data via keystroke logging, clipboard capture, and credential theft. First observed in 2020 and later offered as Malware-as-a-Service (MaaS), it is distributed through phishing emails containing malicious documents.

### Key Features:
- Captures keystrokes, clipboard data, and screenshots
- Exfiltrates data via email (SMTP), FTP, or Telegram bots
- Uses obfuscation and anti-analysis techniques

---

## 🔍 Static Analysis

The malware sample was examined without execution, using tools like PEStudio, PEView, GHIDRA, and VirusTotal. Key observations include:

- **PEStudio**: High VirusTotal detection, suspicious compilation timestamps, high entropy
- **BinText**: Extracted suspicious strings like `keylog`, `sendtoC2`
- **GHIDRA**: .NET based structure, suspicious DLL imports, possible packing
- **CFF Explorer**: Confirmed keylogging-related APIs like `GetAsyncKeyState`, `IsDebuggerPresent`
- **VirusTotal**: Confirmed malicious classification (30+ AV detections)

---

## ⚙️ Dynamic Analysis

Performed in an isolated VM using tools like Process Monitor, Process Explorer, Joe Sandbox, and OllyDbg.

- **Joe Sandbox**: Identified SMTP exfiltration and tagged the sample as Snake Keylogger
- **VMRay**: Revealed process injection, credential theft, and encrypted C2 communications
- **OllyDbg**: Showed .NET dependencies and suspicious DLL interactions
- **Process Monitor**: Logged registry/file modifications, persistence via `schtasks.exe` and `powershell.exe`
- **Process Explorer**: Captured process spawning and immediate termination behavior

---

## 🧯 Mitigation Strategies

- Terminate suspicious processes via Process Explorer or Task Manager
- Reboot in Safe Mode to remove executable manually
- Use antivirus tools for automated detection and removal
- Create System Restore Points before executing unknown files
- Apply AppLocker or SRP policies to block unauthorized apps
- Monitor network traffic for covert data exfiltration
- Educate users on avoiding macro-enabled documents from unknown sources

---

## 🛠️ Tools Used

### Static Analysis:
- PEStudio, PEView, GHIDRA, CFF Explorer, VirusTotal, BinText

### Dynamic Analysis:
- VMRay, OllyDbg, Joe Sandbox, Process Monitor, Process Explorer

### Network & Recon:
- Nmap, NSLookup, Bettercap, Maltego

### Detection & Simulation:
- YARA, Zphisher, Hydra

### Network Security:
- pfSense Firewall

### Operating Systems:
- Windows 7 (target), Kali Linux (analysis tools)

---

## 🧾 Conclusion

This project showcases a comprehensive analysis of Snake Keylogger, emphasizing its advanced capabilities in stealth, persistence, and data exfiltration. It highlights the need for layered security, vigilant monitoring, and user awareness to combat modern malware threats. The use of both static and dynamic tools provides a full-spectrum view of the threat's lifecycle, making this a valuable case study in malware analysis.

---

> **Disclaimer**: This repository is for educational and research purposes only. Do not execute malware samples on a live system.
