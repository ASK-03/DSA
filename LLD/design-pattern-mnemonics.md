# Design pattern mnemonics

**Letter codes to recall all 23 Gang of Four design patterns, with a one-line hook for each.**

```
Creational   FAB SP              5
Structural   ABCD FF P           7
Behavioral   CC II MM O SS T V   11
```

## Creational: FAB SP

Read it as "fab spa".

| Letter | Pattern | One-line hook |
|---|---|---|
| **F** | Factory Method | Subclass decides which class to create |
| **A** | Abstract Factory | A family of related objects that match (e.g. all dark-theme widgets) |
| **B** | Builder | Assemble a complex object step by step |
| **S** | Singleton | One and only one instance |
| **P** | Prototype | Clone an existing object instead of building from scratch |

## Structural: ABCD FF P

The alphabet A to D, then a double F, then P.

| Letter | Pattern | One-line hook |
|---|---|---|
| **A** | Adapter | Plug converter: make one interface fit another |
| **B** | Bridge | Split "what" from "how" so both can vary (shape × renderer) |
| **C** | Composite | Tree where a group behaves like a single item (folder and file) |
| **D** | Decorator | Wrap to add behavior (coffee + milk + sugar) |
| **F** | Facade | One simple front door to a complex system |
| **F** | Flyweight | Share common data across many objects |
| **P** | Proxy | Stand-in that controls access (cache, lazy load, security) |

## Behavioral: CC II MM O SS T V

Four pairs of letters, then three single letters in between and after. Within each pair, the patterns are in alphabetical order.

| Letter | Pattern | One-line hook |
|---|---|---|
| **C** | Chain of Responsibility | Pass the request along until someone handles it |
| **C** | Command | Turn a request into an object (undo, queue, log) |
| **I** | Interpreter | Evaluate sentences in a small language |
| **I** | Iterator | Walk through a collection without knowing its insides |
| **M** | Mediator | Central hub so objects don't talk directly (air traffic control) |
| **M** | Memento | Save and restore a snapshot (undo) |
| **O** | Observer | Subscribe and get notified of changes |
| **S** | State | Behavior changes with internal state (vending machine) |
| **S** | Strategy | Swap algorithms at runtime (payment methods) |
| **T** | Template Method | Fixed recipe steps; subclasses fill in some steps |
| **V** | Visitor | Add operations to classes without editing them |

Some lists cover only 10 behavioral patterns and leave out Interpreter, which is rarely asked. For those, drop one I: **CC I MM O SS T V**.

## Pairs people mix up

| Pair | How to tell them apart |
|---|---|
| State and Strategy | State changes itself; Strategy is chosen by the client |
| Decorator and Proxy | Decorator adds behavior; Proxy controls access |
| Adapter and Facade | Adapter converts one interface; Facade simplifies many |
| Factory Method and Abstract Factory | Factory Method makes one product; Abstract Factory makes a family |
| Mediator and Observer | Mediator is a central hub; Observer is a one-to-many broadcast |

## How to practice

1. Cover the tables and write the three codes from memory.
2. For each letter, name the pattern.
3. For each pattern, say its one-line hook.
