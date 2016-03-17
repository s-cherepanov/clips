(clear)                   ; Memory Leak #1
(progn (release-mem) TRUE)
(mem-used)
(defclass SOURCE (is-a USER))

(deffunction foo()
   (do-for-all-instances ((?x SOURCE)) TRUE
      (bind ?y 0)
      (bogus)))
(clear)                   ; Memory Leak #2
(progn (release-mem) TRUE)
(mem-used)
(defclass SOURCE (is-a USER))

(deffunction foo()
   (do-for-all-instances ((?x SOURCE)) (progn (bind ?y 3) (bogus) TRUE)
      (+ 3 4)))
(clear)                   ; Memory Leak #3
(progn (release-mem) TRUE)
(mem-used)
(deftemplate SOURCE)

(deffunction foo()
   (do-for-all-facts ((?x SOURCE)) TRUE
      (bind ?y 0)
      (bogus)))
(clear)                   ; Memory Leak #41
(progn (release-mem) TRUE)
(mem-used)
(deftemplate SOURCE)

(deffunction foo()
   (do-for-all-facts ((?x SOURCE)) (progn (bind ?y 3) (bogus) TRUE)
      (+ 3 4)))
(clear)                   ; Memory Leak #5
(progn (release-mem) TRUE)
(mem-used)

(defclass FOO (is-a USER)
   (slot value1))

(deffunction foo ()
   (make-instance of FOO
      (value1 (bogus))))
(clear)                   ; Memory Leak #6
(progn (release-mem) TRUE)
(mem-used)

(deftemplate FOO
   (slot value1 (type SYMBOL)))

(defrule foo
   (FOO (value1 ?x))
   =>
   (+ ?x 1)
   (printout t ?x))
(clear)
(progn (release-mem) TRUE)
(mem-used)
(clear)

(deftemplate nar 
   (slot bc))

(defrule migrant 
   (test (eq 1 1))
   (nar (bc ?bc))
   =>
   (printout t ?bc crlf))

(deffacts stuff
   (nar  (bc "US")))
(reset)
(run)
(clear)                   ; SourceForge Bug #12
(defclass Test (is-a USER) (multislot Contents))
(make-instance of Test (Contents a b c d e f g h))

(defrule BrokenPatternMatchBehavior-Object
   (object (is-a Test) 
           (Contents $?first ?second ?third $?fourth ?fifth))
   =>
   (printout t ?first " " ?second " " ?third " " ?fourth " " ?fifth crlf))
(run)
(clear) ;; CLIPSESG Bug

(defclass A (is-a USER)
  (role concrete)
  (slot foo)
  (slot bar))
(make-instance a of A)
(watch all)
(modify-instance a (foo 0))
(unwatch all)
(clear) ;; CLIPSESG Bug

(defclass A
  (is-a USER)
  (role concrete)
  (slot one (type STRING))
  (slot two (type SYMBOL) (allowed-values TRUE FALSE) (default TRUE)))

(definstances TEST (a1 of A) (a2 of A) (a3 of A))

(defrule rule1
  ?obj <- (object (is-a A) (name [a1]))
  =>
  (message-modify-instance ?obj (one "a") (two FALSE))
  (send ?obj print))

(defrule rule2
  ?obj <- (object (is-a A) (name [a2]))
  =>
  (message-modify-instance ?obj (two FALSE) (one "a"))
  (send ?obj print))

(defrule rule3
  ?obj <- (object (is-a A) (name [a3]))
  =>
  (modify-instance ?obj (two FALSE) (one "a"))
  (send ?obj print))
(reset)
(run)
(clear) ;; CLIPSESG Crash Bug

(defrule bug
   (dummy)
   (foo ?x)
   (not (and (huge ?x)
             (not (and (test (eq ?x 1))
                       (bar ?x)))))
   =>)
(reset)
(assert (bar 1))
(assert (huge 1))
(clear) ; SourceForge Bug

(defclass FOO
   (is-a USER)
   (slot _foo (default ?NONE)))
(make-instance foo1 of FOO)
(make-instance foo2 of FOO (_foo))
(clear) ; SourceForge Assert/Clear Bug
(defrule foo (a ?x&:(progn (clear) TRUE)) =>)
(assert (a 1))
(send [initial-object] delete)
(assert (a 2))
(clear)
(assert (a (clear)))
(clear)
(deffacts FOO (foo bar) (foo (clear)))
(reset)
(clear)
(assert-string "(a (clear))")
(clear)
(deftemplate foo (multislot x))
(assert (foo (x (clear) 1)))
(facts)
(modify 1 (x (clear) 2))
(facts)
(clear) ; SourceForge Bug

(defmodule FOO
   (export ?ALL))
   
(defclass FOO::DUMMY 
   (is-a USER)
   (slot foo))
   
(defmodule BAR
   (import FOO ?ALL))

(defclass BAR::BAR 
   (is-a USER)
   (slot bar (allowed-classes DUMMY)))
(set-dynamic-constraint-checking TRUE)

(make-instance b of BAR
   (bar (make-instance f of DUMMY)))
(set-dynamic-constraint-checking FALSE)   
(clear) ; CLIPSESG Bug

(deffunction generate (?a ?c)
   (str-cat ?a ?c))

(deffunction gm1 ()
   (progn$ (?ctype (create$ aaa))
      (generate 2 ?ctype)))

(deffunction gm2 ()
   (bind ?ctype aaa)
   (generate 2 ?ctype))
(gm1)
(gm2)
   
(clear) ; Dangling constructs

(progn
   (clear)
   (build "(defrule foo (count) =>)")
   (assert (count)))
(deftemplate blah (slot x))

(progn 
   (clear)
   (assert (blah (x 1))))
   
(defclass BLAH (is-a USER) (slot x))

(progn
   (clear)
   (make-instance of BLAH (x 1)))
(deffunction yabbo () (printout t "Hello, world!" crlf))

(progn (clear)
       (yabbo))

(defmethod blah ((?x STRING))
   (printout t ?x crlf))

(progn (clear)
       (blah "Hello, world!"))
(clear) ; Sourceforge bug
(funcall str-cat)

(deffunction bar1 (?func)
   (bind $?a (create$))
   (funcall ?func (expand$ $?a)))
(bar1 "str-cat")
(clear)

(defclass BOO (is-a USER)
   (multislot foo (cardinality -1 0)))
   
(defclass BOO (is-a USER)
   (multislot foo (cardinality 0 -3)))
(clear) ; Continuous operation issue
(defglobal ?*num* = 37)
(defglobal ?*val* = FALSE)

(deffunction get-number ()
   (bind ?*num* (+ ?*num* 1)))

(deffunction muck ()
   (bind ?*val* (create$ (get-number) (get-number))))

(deffacts startup
   (muck-around))
   
(defrule muck-around
   ?f0 <- (muck-around)
   =>
   (retract ?f0) 
   (muck)
   (assert (muck-around)))
(reset)
(run 1)
?*val*
(clear) ; SourceForge Crash Bug

(deftemplate table
   (slot table-id (type INTEGER)))

(deftemplate modeler-instance
   (slot class (type SYMBOL) (default ?NONE))
   (slot id (type SYMBOL) (default ?NONE)))

(deftemplate table-modeler-binding
   (slot modeler (type SYMBOL))
   (slot table-id))

(deffacts start
   (table (table-id 100002))
   (table (table-id 100003))
   (modeler-instance (class TIME-PROFILER) (id gen4)) 
   (table-modeler-binding (modeler gen4) (table-id 100003)) 
   (modeler-instance (class TIME-PROFILER) (id gen6))
   (table-modeler-binding (modeler gen6) (table-id 100002)))

(defrule mark   
   (modeler-instance (id ?m1))
   (modeler-instance (id ?m2&~?m1))
   (not (and (table-modeler-binding (modeler ?m1) (table-id ?t1))
             (table-modeler-binding (modeler ?m2) (table-id ?t2&~?t1))
             (table (table-id ?t1))
             (table (table-id ?t2))))
   (not (and
             (table-modeler-binding (modeler ?m2) (table-id ?t3))
             (table-modeler-binding (modeler ?m1) (table-id ?t4&~?t3))
             (table (table-id ?t4))))
   =>)

(defrule remove 
   =>)
(reset)
(matches mark)
(retract 2)
(matches mark)
(retract 3)
(matches mark)
(clear)
(clear) ; DR #882
(watch activations)

(defrule if 
   (not (and (not (and (A) (B)))
             (C)))
   (not (and (SAD ?v)
             (SAD ?v)))
   =>)
(assert (SAD 2))
(clear)

(defrule if 
    (and  
        (exists 
            (SAD T ?tx1 T01 ?t01)
            (SAD T ?tx1 T02 ?t02)
            (or  
                (test (not (not (str-index  "ABCD" ?t01)))) 
                (test (not (not (str-index  "ABCD" ?t02)))))) 
        (exists 
            (SAD G ?gx1 G02N ?g02n)
            (and  
                (test (eq (str-index  "9900" ?g02n) 1)) 
                (exists 
                    (SAD T ?tx2 T08 ?t08)
                    (SAD G ?gx1 G01 ?g01)
                    (or  
                        (test (<= ?t08 0)) 
                        (test (= ?t08 ?g01)))))))
   =>)
(assert (SAD G 2 G01 2))
(assert (SAD G 2 G02N "99009000"))
(assert (SAD T 3 T01 "ABCD XYX"))
(assert (SAD T 3 T02 "XYZ CDE"))
(assert (SAD T 3 T08 2))
(unwatch activations)
(clear)