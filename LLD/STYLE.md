# Article style guide

Every article in this repo follows this guide. It is based on the
[Google developer documentation style guide](https://developers.google.com/style).

## Writing rules

- Use sentence case for all headings: "How the pattern works", not "How The Pattern Works".
- Address the reader as "you". Use active voice and present tense.
- Keep sentences under 25 words. Keep paragraphs to 3 sentences or fewer.
- Use plain words. Write "use", not "utilize"; "start", not "commence".
- Avoid heavy adjectives and hype: no "powerful", "robust", "seamless", "elegant", "crucial", "game-changing".
- Don't use emojis. The only exception is ✅ and ❌ in "do and don't" tables.
- Use numbered lists for steps and bulleted lists for unordered items. Start each item with a capital letter.
- Put code, class names, method names, and file names in `code font`.
- Define a term the first time you use it.
- Use one running example through the whole article. Pick everyday domains: a coffee shop, a library, a music app.
- Write original content. Don't copy text or code from any course or book.

## Formatting rules

- One `#` title per article, then `##` sections, then `###` subsections. Don't skip levels.
- Start with a one-line summary in bold directly under the title.
- Code samples use Java 17. Keep each block under 60 lines. Show only what the reader needs.
- Every article has at least one Mermaid diagram (`classDiagram`, `sequenceDiagram`, `stateDiagram-v2`, or `flowchart`).
- Put a one-sentence caption in italics under each diagram.
- Use tables for comparisons, trade-offs, and requirement lists.
- In Mermaid class diagrams, don't nest generics (`Map~String,List~`, not `Map~String,List~T~~`). Show the full type in the Java code.
- Target length: 700 to 1,500 words for concepts and tips; 1,100 to 2,500 words for interview questions.

## Template: principle, pattern, or tip

```markdown
# <Name>

**<One sentence: what it is and when you use it.>**

## The problem
A short scenario that shows the pain without this idea. Include a small "before" code sample.

## The idea
The core concept in 2 to 3 short paragraphs. Include a diagram.

## How it works
Numbered steps or a list of the parts (roles) and what each one does.

## Example
The "after" code for the same scenario. Explain it in a few bullets below the code.

## When to use it
Bullets.

## When not to use it
Bullets.

## Trade-offs
| Benefit | Cost |
|---|---|

## Common mistakes
Bullets, or a ✅ / ❌ table.

## Related topics
Links to other articles in this repo.

## Key takeaways
3 to 5 bullets.
```

Interview tips use this section order: The problem, The idea, How it works, Worked example, Checklist, Related topics, Key takeaways.

## Template: interview question

```markdown
# Design <system>

**<One sentence: what the system does.>**

## Requirements
### Functional requirements
Numbered list.
### Non-functional requirements
Bullets. Include concurrency and extensibility where relevant.
### Out of scope
Bullets.

## Clarifying questions to ask
A table: question | assumption we make.

## Core entities
A table: entity | responsibility.

## Class diagram
Mermaid `classDiagram` with key fields, methods, and relationships.

## Key flows
One `sequenceDiagram` or `stateDiagram-v2` for the main flow.

## Design patterns used
A table: pattern | where | why.

## Implementation
Java code split into small sections (enums, models, services, entry point).
Each section starts with one sentence saying what it does.

## Handling concurrency
What can race and how the code handles it. Skip this section only if the system is single-threaded by nature.

## Extending the design
2 to 4 follow-up questions an interviewer might ask, each with a short answer.

## Key takeaways
3 to 5 bullets.
```

## File layout

| Folder | Content |
|---|---|
| `principles/` | Design principles |
| `patterns/` | Additional design patterns |
| `tips/` | Interview tips |
| `questions/` | Interview questions |

File names use kebab-case: `patterns/repository-pattern.md`, `questions/design-parking-lot.md`.
