//Author: Aniruddh Kathiriya
//Assignment:3
#include "set.h"
#include <iostream>
#include <cassert>

set::set(){
	used=0;
}
void set::insert(const value_type& entry){
	if(!(contains(entry))){
		assert(size()<CAPACITY);
		data[used]=entry;
		used++;	
	}
}
void set::remove(const value_type& entry){
	for (size_type i=0;i<used;i++ ){
		if(data[i]==entry){
			data[i]=data[used-1];
			used--;
		}
		
	}
}

set::size_type set::size() const{
	return used;
}
bool set::contains (const value_type& entry) const{
	for (size_type i=0;i<used;i++ ){
		if(data[i]==entry){
			return true;
		}
		
	}
	return false;
}
std::ostream& operator << (std::ostream& output, const set& s){
	for(set::size_type i=0;i<s.size();i++){
	output<<s.data[i]<<" ";
	}
	return output;
}
set set_union (const set& s1, const set& s2){
	set s3;
	for(set::size_type i=0;i<s1.size();i++){
		s3.insert(s1.data[i]);
	}
	for(set::size_type i=0;i<s2.size();i++){
		s3.insert(s2.data[i]);
		
	}
	return s3;
}
set set_intersection(const set& s1, const set& s2){
	set s3;
	if(s1.size()>s2.size()){
		for(set::size_type i=0;i<s2.size();i++){
			if(s1.contains(s2.data[i])){
				s3.insert(s2.data[i]);
			}
		}
	}else{
		for(set::size_type i=0;i<s1.size();i++){
			if(s2.contains(s1.data[i])){
				s3.insert(s2.data[i]);
			}
		}
	}

	return s3;
	
}
set set_difference (const set& s1, const set& s2){
	set s3;
		for(set::size_type i=0;i<s2.size();i++){
			if(!(s1.contains(s2.data[i]))){
				s3.insert(s1.data[i]);
			}
		}
	
	return s3;
	
}
bool is_subset (const set& s1, const set& s2){
		for(set::size_type i=0;i<s1.size();i++){
			if(!(s2.contains(s1.data[i]))){
				return false;
			}
		}
		return true;
}
bool operator == (const set& s1, const set& s2){
	if(s1.size()!=s2.size()){
		return false;
	}
	for(set::size_type i=0;i<s2.size();i++){
		if(!(s1.contains(s2.data[i]))){
				return false;
		}
	}
	
	return true;
}
set::size_type set::find (const value_type& entry) const{
	for (set::size_type i=0;i<used;i++ ){
		if(data[i]==entry){
			return i;
		}
		
	}
	return used;
}