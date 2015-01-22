<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="rc-parts">
<packages>
<package name="SOIC-14-WIDE">
<smd name="P$1" x="-2.54" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$2" x="-1.27" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$3" x="0" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$4" x="1.27" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$5" x="2.54" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$6" x="3.81" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$7" x="5.08" y="-2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$8" x="5.08" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$9" x="3.81" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$10" x="2.54" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$11" x="1.27" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$12" x="0" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$13" x="-1.27" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<smd name="P$14" x="-2.54" y="2.54" dx="0.4" dy="1.9" layer="1" rot="R180"/>
<wire x1="-3.19" y1="2.66" x2="-5.14" y2="2.66" width="0.127" layer="21"/>
<wire x1="-5.14" y1="2.66" x2="-5.14" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-5.14" y1="-2.54" x2="-3.19" y2="-2.54" width="0.127" layer="21"/>
<wire x1="5.86" y1="-2.54" x2="7.16" y2="-2.54" width="0.127" layer="21"/>
<wire x1="7.16" y1="-2.54" x2="7.16" y2="2.66" width="0.127" layer="21"/>
<wire x1="7.16" y1="2.66" x2="5.86" y2="2.66" width="0.127" layer="21"/>
<circle x="-4.04" y="-1.34" radius="0.67081875" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ATTINY24A/44A/84A">
<pin name="GND" x="-10.16" y="12.7" length="middle"/>
<pin name="PA0" x="-10.16" y="10.16" length="middle"/>
<pin name="PA1" x="-10.16" y="7.62" length="middle"/>
<pin name="PA2" x="-10.16" y="5.08" length="middle"/>
<pin name="PA3" x="-10.16" y="2.54" length="middle"/>
<pin name="PA4" x="-10.16" y="0" length="middle"/>
<pin name="PA5" x="-10.16" y="-2.54" length="middle"/>
<pin name="PA6" x="-10.16" y="-5.08" length="middle"/>
<pin name="PA7" x="-10.16" y="-7.62" length="middle"/>
<pin name="VCC" x="17.78" y="12.7" length="middle" rot="R180"/>
<pin name="PB0" x="17.78" y="10.16" length="middle" rot="R180"/>
<pin name="PB1" x="17.78" y="7.62" length="middle" rot="R180"/>
<pin name="PB2" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="PB3" x="17.78" y="2.54" length="middle" rot="R180"/>
<wire x1="-5.08" y1="-10.16" x2="-5.08" y2="15.24" width="0.254" layer="94"/>
<wire x1="-5.08" y1="15.24" x2="12.7" y2="15.24" width="0.254" layer="94"/>
<wire x1="12.7" y1="15.24" x2="12.7" y2="-10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="-5.08" y2="-10.16" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATTINY24A">
<gates>
<gate name="G$1" symbol="ATTINY24A/44A/84A" x="-5.08" y="7.62"/>
</gates>
<devices>
<device name="" package="SOIC-14-WIDE">
<connects>
<connect gate="G$1" pin="GND" pad="P$14"/>
<connect gate="G$1" pin="PA0" pad="P$13"/>
<connect gate="G$1" pin="PA1" pad="P$12"/>
<connect gate="G$1" pin="PA2" pad="P$11"/>
<connect gate="G$1" pin="PA3" pad="P$10"/>
<connect gate="G$1" pin="PA4" pad="P$9"/>
<connect gate="G$1" pin="PA5" pad="P$8"/>
<connect gate="G$1" pin="PA6" pad="P$7"/>
<connect gate="G$1" pin="PA7" pad="P$6"/>
<connect gate="G$1" pin="PB0" pad="P$2"/>
<connect gate="G$1" pin="PB1" pad="P$3"/>
<connect gate="G$1" pin="PB2" pad="P$5"/>
<connect gate="G$1" pin="PB3" pad="P$4"/>
<connect gate="G$1" pin="VCC" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="rc-parts" deviceset="ATTINY24A" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="22.86" y="20.32"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
