# sde-interview-prep

Personal end-to-end interview prep repository (DSA, LLD, System Design, CS fundamentals). No build, no tests, no dependencies — this is notes and solved problems, not a codebase that runs.

## Layout

- `DSA/dsa-patterns/` — the main DSA revision material. One file per topic/pattern (two-pointers, DP, graphs, etc.), all following a fixed 6-section format documented in `DSA/dsa-patterns/List of DSA Topics and Patterns.md`. Start there — it links to every other file.
- `DSA/codes/` — solved implementations, organized by topic (Graphs, DisjointSet, heaps, SparseTable) plus loose files (recursion.cpp, sorting.cpp). All code lives under `DSA/`.
- `DSA/questions-worth-a-revise/` — a shorter, curated list of problems flagged for repeat revision.
- `DSA/Problem Solving Framework.md` — general approach notes for tackling a new problem.
- `LLD/` — low-level design. Entry point `LLD/README.md` (full topic list, linked where an article exists), article format in `LLD/STYLE.md`.
- `HLD/` — high-level / system design notes.
- `CS Fundamentals/` — OS, DBMS, CN, OOPS.

## Conventions

- Pattern notes in `DSA/dsa-patterns/` follow the format spec at the top of `List of DSA Topics and Patterns.md`: Recognize It → Core Patterns table → Decision Checklist → Must-Know Problems table → Code Templates → Problem Links. No emojis, no per-file study calendars — keep new notes consistent with this.
- Code templates in pattern notes are C++, kept minimal (no error handling beyond what the algorithm needs).
- One commit per topic/file update, not batched multi-file commits, when editing pattern notes.
