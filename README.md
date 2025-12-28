# github-actions-devops-ci-cd

## Overview

This repository is a hands-on DevOps learning project built from scratch as part of my transition from C/C++ software development to DevOps engineering. It is based on concepts from Microsoft’s *GH-200T00-A: Automate your workflow with GitHub Actions* course and demonstrates CI/CD automation, reusable GitHub Actions, and workflow best practices. All code and repository structure are implemented independently to reinforce practical understanding.

To demonstrate the DevOps skills learned from the course, I chose to build a **Hotel Reservation System in C/C++**, developing it step-by-step while incrementally expanding the CI/CD workflows.

## Main application Features

- View available rooms
- Book a room
- Cancel booking
- Calculate price
- Add discounts for certain nights
- Manage customer details
- Save reservations

## Background

I have 3 years of professional experience as a C/C++ developer. This project reflects my active transition toward DevOps engineering by applying automation principles, an infrastructure mindset, and CI/CD practices commonly used in modern software delivery environments.

## Goals

- Learn and apply CI/CD concepts using GitHub Actions
- Understand and implement different types of GitHub Actions (composite, JavaScript, container)
- Apply DevOps best practices including automation, linting, security, and reusable workflows
- Build production-oriented CI pipelines from scratch rather than copying tutorial code

## Design Principles

- **Reusability**: Actions and workflows designed for reuse  
- **Security-first**: Least-privilege permissions and safe secret handling  
- **Maintainability**: Clear structure, naming, and documentation  
- **Production mindset**: Pipelines designed as they would be in real-world projects  

## Current Status

This project is intentionally developed incrementally to mirror real-world DevOps workflows.
Instead of building everything upfront, functionality and CI/CD capabilities are added step-by-step as concepts are learned, validated, and refined.

## Initial Plan

- Build a simple C/C++ application to act as a realistic workload
- Focus on CI/CD design rather than application complexity
- Separate core logic (library) from executable (application)
- Apply GitHub Actions concepts gradually

## What Has Been Implemented So Far

- Simple Application Architecture
- Modular Hotel Library (core business logic)
- Separate CLI Application consuming the library
- Clean CMake-based build structure
- Clear separation between library tests and application tests

## Testing Strategy

- Unit tests for the hotel library using GoogleTest
- Independent testing of the library without the application
- Application-level tests validating CLI behavior
- Integration tests covering end-to-end flows

## CI/CD Implementation

- GitHub Actions workflow built from scratch
- Library tests executed on:
    - Pull requests
    - Pushes to main
- Application build executed only on Push to main branch
- CI designed to fail fast and provide clear feedback

## CI/CD Pipeline Architecture

This diagram illustrates the structure of our GitHub Actions workflows, including:

- Job dependencies
- Reusable workflows
- Artifact flow
- Build caching

```mermaid
flowchart TD
    %% Nodes
    L[ci-library.yml<br>Build & Test Library<br>Cache + Artifacts]:::lib
    APP[ci-app.yml<br>Build App<br>Optional App Tests<br>Upload Executable]:::app
    Q[ci-quality.yml<br>Lint & Coverage<br>Upload Reports]:::quality
    MATRIX[ci-matrix.yml<br>Multi-OS / Compiler<br>Reusable Build & Test]:::matrix

    %% Artifacts
    ART_LIB[Library Test Reports]:::artifact
    ART_APP[App Executable]:::artifact
    ART_QUALITY[Coverage & Lint Reports]:::artifact

    %% Dependencies
    L -->|Library passes| APP
    L -->|Library passes| Q
    MATRIX -->|Runs reusable workflow| L

    %% Artifacts flow
    L -.-> ART_LIB
    APP -.-> ART_APP
    Q -.-> ART_QUALITY

    %% Styling
    classDef lib fill:#ffd699,stroke:#cc7a00,stroke-width:1px,color:#000;
    classDef app fill:#99ccff,stroke:#0066cc,stroke-width:1px,color:#000;
    classDef quality fill:#ccff99,stroke:#339900,stroke-width:1px,color:#000;
    classDef matrix fill:#ff99cc,stroke:#cc0066,stroke-width:1px,color:#000;
    classDef artifact fill:#eeeeee,stroke:#333333,stroke-width:1px,color:#000;


## Planned Implementations / Next Steps

| Status | Item                                                                    |
| ------ | ----------------------------------------------------------------------- |
| ✅      | Modular CMake project structure                                         |
| ✅      | Library unit tests with GoogleTest                                      |
| ✅      | Application build and CLI validation                                    |
| ✅      | CI pipeline for library and applicationvalidation                       |
| ⏳      | CI pipeline enhancements (linting, static analysis, and extended checks) |
| ⏳      | Reusable GitHub workflows (`workflow_call`)                             |
| ⏳      | Custom composite GitHub Actions                                         |
| ⏳      | Matrix builds (OS / compiler versions)                                  |
| ⏳      | Pipeline caching for faster builds                                      |
| ⏳      | Security scanning (dependencies, secrets and configuration scanning)    |
| ⏳      | Code coverage reporting                                                 |
| ⏳      | CI/CD architecture diagrams                                             |
| ⏳      | Artifacts generated for application binaries                            |

## Build and Test

This project uses CMake and a standard out-of-source build.

# Build
cmake -S . -B build
cmake --build build

This will build:

- The hotel core library
- The CLI application
- All configured test targets

Run Tests

To run all tests (library plus App):

ctest --test-dir build --output-on-failure


To build and run only the hotel library tests:

cmake --build build --target hotel_lib_tests
ctest --test-dir build -R hotel_lib_tests

## Credits

Inspired by concepts from Microsoft’s official course *GH-200T00-A: Automate your workflow with GitHub Actions*: [Course Link](https://learn.microsoft.com/en-us/training/courses/gh-200t00)  

This repository is not a fork. All implementations are independent and intended for learning and demonstration purposes.
