# Low-Level Design (LLD)

Notes on object-oriented design principles, design patterns, interview techniques, and common LLD interview questions.

**Quick references:** [When to use principles and patterns](when-to-use-what.md) · [Design pattern mnemonics](design-pattern-mnemonics.md) · [Article style guide](STYLE.md)

> The articles in this section were generated with Claude (Anthropic) from topic titles only. No third-party course content was used.

Linked topics have an article. Unlinked topics are on the list but not written yet.

## Fundamentals
- What is LLD · LLD vs HLD · Types of LLD Interviews

## OOP Concepts
- Classes and Objects · Enums · Interfaces · Encapsulation · Abstraction · Inheritance · Polymorphism

## Class Relationships
- Association · Aggregation · Composition · Dependency · Realization

## Design Principles
- DRY · KISS · YAGNI · Law of Demeter
- [Separation of Concerns](principles/separation-of-concerns.md)
- [Coupling and Cohesion](principles/coupling-and-cohesion.md)
- [Composing Objects Principle](principles/composing-objects-principle.md)
- [Composition over Inheritance](principles/composition-over-inheritance.md)

## SOLID
- Single Responsibility · Open/Closed · Liskov Substitution · Interface Segregation · Dependency Inversion

## UML
- Class Diagram · Use Case Diagram · Sequence Diagram · Activity Diagram · State Machine Diagram

## Design Patterns
See [mnemonics](design-pattern-mnemonics.md) for remembering all of them.
- **Creational:** Singleton · Builder · Factory Method · Abstract Factory · Prototype
- **Structural:** Adapter · Bridge · Composite · Decorator · Facade · Flyweight · Proxy
- **Behavioral:** Chain of Responsibility · Command · Interpreter · Iterator · Mediator · Memento · Observer · State · Strategy · Template Method · Visitor

## Additional Patterns
- Null Object
- [Repository](patterns/repository-pattern.md)
- [MVC](patterns/mvc-pattern.md)
- [Dependency Injection](patterns/dependency-injection-pattern.md)
- [Specification](patterns/specification-pattern.md)
- [Game Loop](patterns/game-loop-pattern.md)
- [Thread Pool](patterns/thread-pool-pattern.md)
- [Producer-Consumer](patterns/producer-consumer-pattern.md)

## Interview Tips
- Approach OOD Interviews · Approach Machine Coding Interviews
- [Identify Entities and Relationships](tips/identify-entities-and-relationships.md)
- [Write Clean Code](tips/write-clean-code.md)
- [Choose Design Patterns](tips/choose-design-patterns.md)
- [Handle Concurrency](tips/handle-concurrency.md)

## Interview Questions

**Games and Data Structures**
- Tic Tac Toe · Snake and Ladder · LRU Cache · Bloom Filter · [Chess](questions/design-chess-game.md) · [Minesweeper](questions/design-minesweeper-game.md) · [Search Autocomplete](questions/design-search-autocomplete-system.md) · [Simple Search Engine](questions/design-simple-search-engine.md)

**Machines and Controllers**
- [ATM](questions/design-atm.md) · [Vending Machine](questions/design-vending-machine.md) · [Coffee Vending Machine](questions/design-coffee-vending-machine.md) · [Elevator System](questions/design-elevator-system.md) · [Traffic Control System](questions/design-traffic-control-system.md) · [Parking Lot](questions/design-parking-lot.md)

**Management Systems**
- [Task Management](questions/design-task-management-system.md) · [Inventory Management](questions/design-inventory-management-system.md) · [Library Management](questions/design-library-management-system.md) · [Restaurant Management](questions/design-restaurant-management-system.md)

**Social and Content**
- Stack Overflow · [Social Network](questions/design-social-network.md) · [LinkedIn](questions/design-linkedin.md) · [Spotify](questions/design-spotify.md) · [Cricinfo](questions/design-cricinfo.md) · [Learning Platform](questions/design-learning-platform.md) · [Chat Application](questions/design-chat-application.md) · [Notification System](questions/design-notification-system.md) · [Pub-Sub System](questions/design-pub-sub-system.md)

**Payments and Commerce**
- [Splitwise](questions/design-splitwise.md) · [Payment Gateway](questions/design-payment-gateway.md) · [Online Stock Exchange](questions/design-online-stock-exchange.md) · [Shopping Cart](questions/design-shopping-cart.md) · [Amazon](questions/design-amazon.md) · [Amazon Locker](questions/design-amazon-locker.md)

**Booking and Services**
- [Movie Booking](questions/design-movie-booking-system.md) · [Car Rental](questions/design-car-rental-system.md) · [Meeting Scheduler](questions/design-meeting-scheduler.md) · [Online Auction](questions/design-online-auction-system.md) · [Food Delivery](questions/design-food-delivery-service.md) · [Ride Hailing](questions/design-ride-hailing-service.md)

**Infrastructure**
- [Logging Framework](questions/design-logging-framework.md) · [URL Shortener](questions/design-url-shortener.md) · [Rate Limiter](questions/design-rate-limiter.md) · [In-Memory File System](questions/design-in-memory-file-system.md) · [Task Scheduler](questions/design-task-scheduler.md) · [Version Control System](questions/design-version-control-system.md)
