---
publishDate: 2026-05-24T00:00:00Z
title: VitalRest Prototype 1
excerpt: A non-wearable sleep apnea monitoring and alert system utilizing mattress-based micro-vibration sensing designed for resource-constrained households.
image: vitalrest-prototype-1/overview-system.jpg
tags:
  - biomedical-engineering
  - embedded-systems
  - sleep-apnea
---

> Non-wearable, power-resilient sleep apnea monitoring engineered for African households.

---

## Acknowledgements
This engineering prototype was developed under the academic supervision of the Department of Biomedical Engineering at Ernest Cook University (ECU), Kampala, Uganda. We extend our sincere gratitude to our faculty mentor, Dr. Bashir Bwogi, for providing institutional support, technical oversight, and laboratory access.We also thank the laboratory in charge, Eng. Senyonjo Timothy, for providing directional insight and transportation expenses. We also thank the IEEE Sensors Council and the MYOSA 5.0 organizing committee for providing the core modular hardware ecosystem used to deploy this solution toward critical local public health challenges.

---

## Overview
Every night across Uganda, life-threatening conditions like obstructive sleep apnea (OSA) remain entirely invisible because sub-Saharan Africa lacks accessible diagnostic infrastructure; Uganda has zero accredited sleep labs. Existing consumer sleep monitors fail locally because they rely on continuous internet connectivity, active companion smartphones, or stable main grids, and require body-worn sensors that disrupt sleep. 

**VitalRest Prototype 1** addresses this gap by providing a completely non-wearable, standalone, two-module sleep monitoring system tailored specifically for Ugandan home environments (such as floor mats, common power grid blackouts, and low-connectivity settings). By analyzing mattress-level mechanical micro-vibrations from a patient’s breathing, the system calculates respiratory variance locally using edge-computing methodologies. It delivers graduated physical sound alerts if breathing ceases, all while remaining capable of running autonomously on long-term backup battery power.

**Key features:**
* **Non-Wearable Sensing:** Passive under-mattress baseline tracking with zero body contact.
* **Universal Surface Optimization:** Calibrated for raised spring beds, flat-base beds, and traditional floor mats.
* **Edge-Based Processing:** Real-time variance extraction running completely local without internet dependencies.
* **Power-Outage Resilience:** Dual-power configuration capable of maintaining uninterrupted operation during grid dropouts.

---

## Demo / Examples

### **Images**

<p align="center">
  <img src="/assets/images/vitalrest-prototype-1/cover-image.jpg" width="800"><br/>
  <i>Figure 1: Cover image showing connected components of the SensoPad (a motion sensor on the black surface) and the BedUnit hub (display, buzzer and motherboard)</i>
</p>

<p align="center">
  <img src="/assets/images/vitalrest-prototype-1/display-showing-monitoring.jpg" width="800"><br/>
  <i>Figure 2: Display showing monitoring</i>
</p>

<p align="center">
  <img src="/assets/images/vitalrest-prototype-1/display-showing-apnea.jpg" width="800"><br/>
  <i>Figure 3: Display showing Apnea</i>
</p>

### **Videos**

<video controls width="100%">
  <source src="/vitalrest-demo.mp4" type="video/mp4">
</video>

---

## Features (Detailed)

### **1. Micro-Vibration Ballistocardiography Sensing**
The system uses high-sensitivity instrumentation lines placed entirely beneath the sleeping platform. By capturing millivolt-scale mechanical displacements from chest wall expansions, it isolates breathing signals through mattress materials without attaching modules to the patient's body.

### **2. Edge-Computing Apnea Classification**
The firmware executes a rolling variance calculation loop on an isolated core over a sliding time-window block. If the processed respiratory amplitude falls below the calibrated `BREATH_THRESHOLD` continuously for more than 15–20 seconds, the device bypasses cloud checking to immediately log an apnea event locally.

### **3. Standalone Graduated Audio Escalation**
To bypass smartphone alarm dependencies, an active physical buzzer scales acoustic volume across three distinct duty cycles tied to time thresholds (15s, 20s, and 25s delays). This safely alerts families or awakes the user, dropping state automatically when physiological movement resumes.

---

## Usage Instructions
1. Position the sensing core (SensoPad containing the MPU6050 assembly) securely flat beneath the center of the sleeping mattress or floor mat.
2. Mount the BedUnit controller module on a level bedside surface and link the system data cable.
3. Attach a 5V DC power line via a standard USB adapter or external battery bank to initiate the hardware initialization loop.
4. Monitor the high-contrast OLED display to confirm baseline status reads `Monitoring` with a bar running across for breathing rhythm.

If building or flashing the code configuration yourself, compile the repository source via the Arduino IDE using standard board managers:

```plaintext
// Ensure your target compiler is configured for ESP32 Dev Module architectures before building.