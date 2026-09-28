# When to use principles and patterns

**Use them in order: keep code simple by default, clean it up once it works, and add abstraction only where change actually happens. A design pattern is the named shape that abstraction usually takes.**

```
1. SIMPLE      KISS, YAGNI              always, while writing
2. CLEAN       DRY, SRP, naming         once it works
3. FLEXIBLE    OCP, DIP, LSP, ISP, LoD  only where things change
4. PATTERNS    Strategy, Observer, ...  the named fix for a step-3 problem
```

Each layer only applies once the layer above it is satisfied. Most over-engineered code comes from starting at layer 4.

## Layer 1: Simple (every line you write)

| Principle | Question to ask |
|---|---|
| KISS | Is there a plainer way to write this? |
| YAGNI | Does a current requirement need this, or am I guessing? |

These are the default. Write the most direct code that meets the requirement: one class, one method, an `if` statement. Don't add interfaces, factories or config "for later".

## Layer 2: Clean (after it works)

| Principle | Trigger | Action |
|---|---|---|
| DRY | The same logic appears a third time | Extract a method or class |
| SRP | Describing the class needs the word "and" | Split it |
| Naming | You need a comment to explain what a name means | Rename it |

**Rule of three:** duplicating something once is fine. Extract it the third time. If you extract too early, you can join two things that only look alike and later need to change separately.

## Layer 3: Flexible (only at change points)

Apply these where a requirement changes, a new variant appears, or testing is painful. Don't apply them everywhere.

| Symptom in your code | Principle | Typical fix |
|---|---|---|
| `if/else` or `switch` on a type keeps growing | OCP | Polymorphism, Strategy or State |
| `new PaymentService()` inside business logic makes testing hard | DIP | Pass in an interface (dependency injection) |
| A subclass throws `UnsupportedOperationException` | LSP | Use composition instead of inheritance |
| Classes implement interface methods they don't need | ISP | Split the interface |
| A call chain like `order.getCustomer().getAddress().getCity()` | LoD | Ask the nearest object: `order.shippingCity()` |

## Layer 4: Patterns (the named fix)

A pattern is the answer to a layer-3 problem that has come up often enough to get a name. Start from the problem and find the pattern; never pick a pattern first.

| Problem you have | Pattern |
|---|---|
| Several ways to do one job, chosen at runtime | Strategy |
| Behavior depends on the current status | State |
| Many objects must react when one changes | Observer |
| Object creation is complex or has many optional fields | Builder |
| The caller shouldn't know which concrete class it gets | Factory Method |
| An existing class has the wrong interface | Adapter |
| You need to add features in combinations | Decorator |
| A subsystem is too complex for callers | Facade |
| You need undo | Command + Memento |

See [design pattern mnemonics](design-pattern-mnemonics.md) for all 23 patterns.

## When principles conflict

| Conflict | Who wins |
|---|---|
| DRY vs KISS | KISS, until the rule of three triggers DRY |
| YAGNI vs OCP | YAGNI, until a second variant actually appears. Then refactor for OCP. |
| SRP vs KISS | Split only when the parts change for different reasons |
| Pattern vs plain code | Plain code, unless you can name the change point in one sentence |

## When to check each layer

1. **Writing:** layer 1 only. Make it work plainly.
2. **Tests pass:** layer 2. Remove the third copy of duplicated code, split classes that do two jobs, fix names.
3. **A new requirement or variant arrives:** layer 3. Find the spot that changed and put an interface there.
4. **Code review:** ask one question per layer. Is it simple? Is it clean? Is the flexibility justified by a real change? Is each pattern's reason one sentence?

## In an LLD interview

Interviews reverse the timing, because the interviewer tells you up front what will change: "support other payment methods", "add new vehicle types".

1. List the entities and keep them simple (layer 1).
2. Give each class one job (layer 2).
3. Circle each stated or likely change point and put an interface there (layer 3).
4. Name the pattern at each circle, and say why in one sentence (layer 4).
5. Leave everything else as plain classes. Saying "I kept X simple because nothing about it varies" earns points.

The [parking lot article](questions/design-parking-lot.md) does this. Spot assignment and pricing are the change points, so each gets a Strategy, and everything else is plain classes.

## Related topics

- [How to choose design patterns](tips/choose-design-patterns.md)
- [Coupling and cohesion](principles/coupling-and-cohesion.md)
- [Composing objects principle](principles/composing-objects-principle.md)
