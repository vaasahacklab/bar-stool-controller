difference(){
	cube([30,10,8]);
	translate([5,0,2]) cube([20,10,6]);
	translate([2.5,5,0])cylinder(r=1.5,h=8);
	translate([30-2.5,5,0])cylinder(r=1.5,h=8);

}

translate([10.5,2.5,0])cylinder(r=1,h=4);
translate([19.5,2.5,0])cylinder(r=1,h=4);