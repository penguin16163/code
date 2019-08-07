var l,r,k,n,x,i,cnt:longint;
    s:array[0..105] of ansistring;
    st:ansistring;
function check(str:ansistring):boolean;
var i:longint;
    flag:boolean;
begin
  flag:=false;
  for i:=1 to n do
    if (pos(s[i],str)<>0) then flag:=true;
  exit(flag);
end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(l, r, k, n);
  for i:=1 to n do
    begin
      read(x);
      str(x, s[i]);
    end;
  for i:=l to r do
    begin
      str(i,st);
      if (check(st)) then inc(cnt)
      else continue;
      if (cnt=k) then
        begin
          writeln(i);
          close(input);
          close(output);
          halt;
        end;
    end;
  writeln('-1');
  close(input);
  close(output);
end.

