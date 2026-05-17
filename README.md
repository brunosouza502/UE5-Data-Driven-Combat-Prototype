# UE5-Data-Driven-Combat-Prototype

## Overview
This project is a gameplay-focused prototype developed in Unreal Engine 5, exploring data-driven ability system for melee combat.

The goal was to design a clean, scalable combat architecture using Blueprints, focusing on gameplay clarity, state management, and animation-driven execution.

---

## Core Features

### Data-Driven Ability System
- Modular AbilityBase structure
- Ability configuration through Data Assets
- Extensible architecture for new abilities

### Light Attack Ability
- Animation-driven attack via AnimNotifies
- Trace-based hit detection

### Block System (Directional Defense)
- Player can enter a blocking state via ability
- Damage is prevented only when facing the attacker
- Uses vector math (Dot Product) to validate direction

### Enemy AI
- Basic chase behavior (MoveTo Player)
- Attack ability execution
- Supports multiple enemies with avoidance improvements

---

## Technical Highlights

- Gameplay Ability-oriented architecture (Blueprint-based)
- Separation between state, animation, and damage systems
- Clean handling of:
  - Ability activation
  - State control (blocking, attacking)
  - Animation → gameplay synchronization

---

## Technologies & Tools

- Unreal Engine 5.7
- Blueprints (primary)
- Basic C++ knowledge (ongoing learning)
- Animation Montages & State Machines
- NavMesh + AI Behavior

---

## Design Decisions

- Block is implemented as a state (not montage), ensuring clarity and stability
- Movement is disabled during blocking to reinforce player commitment
- Combat is animation-driven to avoid hard-coded timing
- Systems are intentionally scoped as a prototype (not a full game)

---

## Demo

Gameplay Video (YouTube): [https://www.youtube.com/watch?v=DuNRWdIbilg]  

---

## Notes

This is a systems-focused prototype intended to demonstrate gameplay architecture and design thinking rather than visual polish or full game completeness.

---

## What This Demonstrates

- Gameplay Systems Design
- State-safe architecture
- Combat loop understanding (attack ↔ defense)
- Clear integration between animation and gameplay logic
- 
- External assets were removed to keep the repository lightweight.

This project focuses on gameplay systems and logic implementation.
