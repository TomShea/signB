<?php

// Script to generate pixelMap

//  Initialize
$r = '{ {';

// Row 1 (top of head)
$r .= n(55);
$r .= a(1, 44, 44);
$r .= n(55);
$r .= e();

// Row 2
$r .= n(54);
$r .= a(1, 43, 42);
$r .= n(55);
$r .= e();

// Row 3  (top of wings)
$r .= a(0, 265, 228);
$r .= n(16);
$r .= a(1, 39, 41);
$r .= n(16);
$r .= a(2, 228, 265);
$r .= e();

// Row 4
$r .= n(2);
$r .= a(0, 190, 227);
$r .= n(13);
$r .= a(1, 38, 35);
$r .= n(14);
$r .= a(2, 227, 190);
$r .= n(2);
$r .= e();

// Row 5
$r .= n(4);
$r .= a(0, 189, 152);
$r .= n(11);
$r .= a(1, 30, 34);
$r .= n(11);
$r .= a(2, 152, 189);
$r .= n(4);
$r .= e();

// Row 6
$r .= n(6);
$r .= a(0, 114, 151);
$r .= n(8);
$r .= a(1, 29, 24);
$r .= n(9);
$r .= a(2, 151, 114);
$r .= n(4);
$r .= e();

// Row 7
$r .= n(8);
$r .= a(0, 113, 76);
$r .= n(6);
$r .= a(1, 17, 23);
$r .= n(6);
$r .= a(2, 76, 113);
$r .= n(8);
$r .= e();

// Row 8
$r .= n(10);
$r .= a(0, 38, 75);
$r .= n(3);
$r .= a(1, 16, 9);
$r .= n(4);
$r .= a(2, 75, 38);
$r .= n(10);
$r .= e();

// Row 9 (bottom of head and wings)
$r .= n(12);
$r .= a(0, 37, 0);
$r .= n(1);
$r .= a(1, 0, 8);
$r .= n(1);
$r .= a(2, 0, 37);
$r .= n(12);
$r .= e();

// Row 10 (spacer)
$r .= n(111);
$r .= e();

// Row 11 (top of body upper)
$r .= n(24);
$r .= a(3, 62, 0);
$r .= n(24);
$r .= e();

// Row 12
$r .= n(26);
$r .= a(3, 63, 121);
$r .= n(26);
$r .= e();

// Row 13
$r .= n(28);
$r .= a(3, 176, 122);
$r .= n(28);
$r .= e();

// Row 14
$r .= n(30);
$r .= a(3, 177, 227);
$r .= n(30);
$r .= e();

// Row 15 (bottom of body upper)
$r .= n(32);
$r .= a(3, 228, 274);
$r .= n(32);
$r .= e();

// Row 16 (spacer)
$r .= n(111);
$r .= e();

// Row 17 (top of body lower)
$r .= n(37);
$r .= a(4, 0, 36);
$r .= n(37);
$r .= e();

// Row 18
$r .= n(39);
$r .= a(4, 69, 37);
$r .= n(39);
$r .= e();

// Row 19
$r .= n(41);
$r .= a(4, 70, 98);
$r .= n(41);
$r .= e();

// Row 20
$r .= n(43);
$r .= a(4, 123, 99);
$r .= n(43);
$r .= e();

// Row 21 (bottom of body lower)
$r .= n(45);
$r .= a(4, 124, 144);
$r .= n(45);
$r .= e();

// Row 22 (spacer)
$r .= n(111);
$r .= e();

// Row 23 (top of tail)
$r .= n(48);
$r .= a(5, 13, 0);
$r .= n(49);
$r .= e();

// Row 24
$r .= n(50);
$r .= a(5, 14, 23);
$r .= n(51);
$r .= e();

// Row (bottom of tail)
$r .= n(52);
$r .= a(5, 29, 24);
$r .= n(53);
$r .= e();

$r .= '}';

echo $r;

function n($count) {
    $r = '';
    $e = '{-1,-1}, ';
    for($i = 0; $i < $count; $i++) {
        $r .= $e;
    }
    return $r;
}

function a($pin, $start, $end) {
    $r = '';
    if ($start > $end) {
        for($i = $start; $i >= $end; $i--) {
            $r .= '{' . "$pin, $i}, ";
        }
    } else {
        for($i = $start; $i <= $end; $i++) {
            $r .= '{' . "$pin, $i}, ";
        }
    }
    return $r;
}

function e(){
    return ' },' . PHP_EOL . '{';
}
