# 23F-3060_OOP_PROJECT_PHASE_1
OOP FINAL PROJECT PHASE 1 
Medieval Society Simulation
This C++ project simulates a medieval-style society with dynamic systems including economy, leadership, military, events, and citizens. It is structured using object-oriented programming and demonstrates interaction between various societal components.
Code Structure

 economy.h / economy.cpp
 event.h / event.cpp
 leader.h / leader.cpp
 military.h / military.cpp
 person.h / person.cpp
 society.h / society.cpp
Features
🔧 Core Components
Society Class: Central class managing population, food, tax, money, happiness, and coordination of systems like economy and military.

Person System: Randomly generates people with different roles (Peasant, Noble, Doctor, etc.) and names.

Military System: Manages soldiers, morale, and desertions.

Economy System: Applies inflation to the society’s finances.

Leader System: Simulates different government types (King, Council, Dictator) with effects on society and chance of coup.

Random Events: Includes events like Famine, Disease, War, and Rebellion that dynamically affect the society.

💾 File I/O
Save/load society state to/from file.

🕹 Gameplay Loop
Society is updated continuously in a loop:

Consumes food

Collects tax

Triggers random events

Applies military, leadership, and economic changes
💡 Highlights
Dynamic Memory Allocation for growing population.

Friend Classes used for access to internal members.

Enums for clean role and event type management.

Simple UI with cout and console formatting.

Object-Oriented Design with high modularity.

📌 To Do
Add more detailed UI

Implement saving/loading to text or binary files

Handle edge cases (e.g., economy crash or 0 population)
