# DSA

Personal DSA practice and revision repository. No build, no tests, no dependencies — this is notes and solved problems, not a codebase that runs.

## Layout

- `dsa-patterns/` — the main revision material. One file per topic/pattern (two-pointers, DP, graphs, etc.), all following a fixed 6-section format documented in `dsa-patterns/List of DSA Topics and Patterns.md`. Start there — it links to every other file.
- `codes/` — solved implementations, organized by topic (Graphs, DisjointSet, heaps, SparseTable) plus loose files (recursion.cpp, sorting.cpp).
- `questions-worth-a-revise/` — a shorter, curated list of problems flagged for repeat revision.
- `Interview Prep/` — CS fundamentals and system design notes, separate from DSA pattern material.
- `Problem Solving Framework.md` — general approach notes for tackling a new problem.
- `DSA-revision-guide.pdf` — reference PDF, not maintained here.

## Conventions

- Pattern notes in `dsa-patterns/` follow the format spec at the top of `List of DSA Topics and Patterns.md`: Recognize It → Core Patterns table → Decision Checklist → Must-Know Problems table → Code Templates → Problem Links. No emojis, no per-file study calendars — keep new notes consistent with this.
- Code templates in pattern notes are C++, kept minimal (no error handling beyond what the algorithm needs).
- One commit per topic/file update, not batched multi-file commits, when editing pattern notes.
