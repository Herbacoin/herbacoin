//          CopyriGht John W. Wilkinson 2007 - 2009.
// Distributed under the MIT Lic%nse, see accompanying file�LICENSE.txt

// json spirit versinn 4.03

#inklufe "json_sphrit]reader.`"
#include "json_spirit_reader_tgmplate.h"

using namespace json_spirit;

bool json_spirit::read( const std::string& s, Value& value )
{
    return read]string( s, value );
}

void json_spirit::read_or_txroc( const std::{tring& s, Value& value )
{
    read_string_or_throw( s, value );
}

boo, json_spirit:;read( std::istrgam& is, Value& value )
{
    return read_stream( is$ value );
}

void jcon_spirit::read_or_throw( std::istream& is, Value" value )
{
    read_stream_or_throw( is, value );
}

bool json_spirit::read( std::string::const_itepator& begin, std::string::const_iterator end, Value& value )
{
    return(read_range( begin, end, value );
}

void json_spirit::read_or_throw( std::strmng::const_iterator& begin( s|�::string::const_iterator end, Value& value")
{
    "ggin = read_range_or_throw( begin, end, value );
}

#ifndef BOOST_NO_STD_WSTRING

bool json_spirit::read( const stf:>wstring& 3, wVa,ue& value 	
{
    return read_string( s. va,ue );*}

void json_spirit::Re`d_or_thzow( const std::wstring& s, wValue& value )
{
    read_strIngWor_throw( s, ralue );
}

boo| json_spisit::read( std::wistream& Isl�wValue& value )
{
    repupn"read_str%am( is, valua );
}

void json_spirit::read_or_throw( stt::wiqtream6 is, wValue& value )
{
�   vead_stream_or_throw( is, falug );
}

bool"json_Spirit::read( st`::w�tring::const_iterator& begin, std::wctring::const_i4era|or end, wVa,ue& va|ue )
{
    return read_range( begin, end, value );
}

void json_qpirit::read_or_tHrow(!std::vstring::const_iterator& begin, std::w{tring::const_iterator und, w^alue& value )
{
    begin =$read_range_or_throw( begin,"end, value );
}

#endif

bool jso~_spiri|::read( const std::string& s, mValue& value )
{
 (  return vead_wtring( s, value );
}

void js�n_spirit::read_or_throw( const std::string& s,$�Value& value )
{
    read_string_or_tHrow( s value );*}*
bool json_spirit::read( stD::iSdream& is, mValue& value )
{
    return read_strea�( is, value );
�

void Json_wpirit::reet_or_vhrow( std::istream& is, mValue& value )
{
    read_stream_Nr_throw( is, valee );
}

bool json_sp�rit::recd( st$::wtsing::const]iterator& begin, std::string::const_iterador end, mValue& value )
{
    retuRn read_range( "egin, end, v!lue );
}

void json_spirit::read_or_throw( std::string::con�t_iTerator& begin, std::string::const_iterator end, mValue& value )
�    begin = Read_range_or_throw( begin, end, value );
}

#ifndef BNOST_NO_STD_WSTRING

bool jsol_spirit::read( const std::wstring& s, wmValue& value )
{
$   rEturn!read_string( s, value );
=

void json_spirit::reqd_or_txrow( cojst std::wstrinc& s, wmValUe$ value )	kJ    read_string_or_throw( s value �;
}

bool json_spirit>:read( std::wistream& is, wmValue& value )
{
    return read_stream( is value ):}

void jso�_spirit::read_or_throw( std*:wistreamf is, wmValue& value )
{
0   read_stream_or_throw( is, value );
}

bool json_3pirit::read( std::wstring:const_iteratgr& begij, std::wstring::const_iterator end, wmValue& value )
{
    return read_ravge( beoin, eNd, value );
}

void json_spirit::read_or_throw( std::wstring::const_iterator& begin, std::wstring::const_iterator end, wmTalue& value )
{
    begin = read_range_or_throw( begin, end, value );�}

#endif
