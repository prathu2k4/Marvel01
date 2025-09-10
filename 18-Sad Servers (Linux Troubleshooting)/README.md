
# Command Line Murders – Sad Servers 🕵️‍♂️

This is the walkthrough and solution for solving the **Command Line Murders (Sad Servers)** mystery using Linux command-line tools.

---

## Steps to Solve the Case

### 1. Read the Instructions

```bash
cat instructions
```

### 2. Collect Initial Clues from Crimescene

```bash
grep CLUE crimescene
grep CLUE crimescene >> clues.txt
```

From analysis of the collected clues, we discover:

* The murderer is **male**
* Height **at least 6’**
* Had **membership cards** for:

  * Rotary Club
  * Delta SkyMiles
  * Terminal City Library
  * Museum of Bash History

Also, a **witness named Annabel** was mentioned by a barista.

---

### 3. Identify Common Memberships

We need to find members common to all 4 organizations:

```bash
cat memberships/Rotary_Club memberships/Delta_SkyMiles memberships/Terminal_City_Library memberships/Museum_of_Bash_History \
  | sort | uniq -c | grep 4
```

Save the results:

```bash
cat memberships/Rotary_Club memberships/Delta_SkyMiles memberships/Terminal_City_Library memberships/Museum_of_Bash_History \
  | sort | uniq -c | grep 4 > suspects
```

---

### 4. List All Men

Extract male suspects from the people database:

```bash
cat people | grep '\sM\s' | awk '{print $1,$2}' | sort > men
```

---

### 5. Track the Witness – Annabel

Search for people named Annabel:

```bash
cat people | grep Annabel
```

This shows **4 Annabels** with their addresses. Using these addresses, open the relevant **streets files** and note their interview numbers.

---

### 6. Read the Interviews

View each interview:

```bash
cat interviews/<interview_number>
```

From interviews, we learn:

* Suspect drove a **blue Honda**
* License plate starts with **L337** and ends with **9**

---

### 7. Check Vehicle Records

Search the vehicles database:

```bash
head vehicles | grep L337 > suspect_vehicles
```

---

### 8. Cross-Reference Suspects

Now we have three sets of data:

* `suspects` (membership cross-match)
* `men` (male list)
* `suspect_vehicles` (vehicle ownership)

By cross-referencing, the common name appears:
**Joe Germuska**

---

### 9. Final Answer

Save the murderer’s name as solution:

```bash
echo "Joe Germuska" > ~/mysolution
md5sum ~/mysolution
```

---

## ✅ Murderer Identified

**Joe Germuska** is the killer.
