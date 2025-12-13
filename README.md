# github-actions-devops-ci-cd

## Overview

This repository is a hands-on DevOps learning project built from scratch as part of my transition from C/C++ software development to DevOps engineering. It is based on concepts from Microsoft’s *GH-200T00-A: Automate your workflow with GitHub Actions* course and demonstrates CI/CD automation, reusable GitHub Actions, and workflow best practices. All code and repository structure are implemented independently to reinforce practical understanding.

To demonstrate the DevOps skills learned from the course, I chose to build a **Hotel Reservation System in C/C++**, developing it step-by-step while incrementally expanding the CI/CD workflows.

## Main Features

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

## Current Status

The project is under active development. The repository structure and roadmap are defined, and CI/CD components will be implemented incrementally as concepts are applied and validated.

## Planned Implementations / Next Steps

- Design and implement CI/CD workflows from scratch using GitHub Actions
- Create reusable workflows using `workflow_call`
- Develop reusable custom actions (composite, JavaScript, and container-based)
- Implement CI pipeline automation including linting, validation, and execution flow
- Introduce caching mechanisms to optimize pipeline performance
- Add matrix builds for multi-version or multi-platform testing
- Expand security checks including dependency, secret, and configuration scanning
- Maintain a clean, scalable repository structure with clear documentation
- Document CI/CD architecture and workflow design using diagrams

## Design Principles

- **Reusability**: Actions and workflows designed for reuse  
- **Security-first**: Least-privilege permissions and safe secret handling  
- **Maintainability**: Clear structure, naming, and documentation  
- **Production mindset**: Pipelines designed as they would be in real-world projects  

## Credits

Inspired by concepts from Microsoft’s official course *GH-200T00-A: Automate your workflow with GitHub Actions*: [Course Link](https://learn.microsoft.com/en-us/training/courses/gh-200t00)  

This repository is not a fork. All implementations are independent and intended for learning and demonstration purposes.
