// $Id: README.txt,v 1.1 2009/01/08 12:31:34 clemenstolboom Exp $

When using remote files one has to take care about
the license that file has. In order to use a remote file
on your local server you need to know at least 
where the file came from.

This module requires:
- CCK filefield
- CCK imagefield
- CCK link

Setup:
- make a CCK field_remote_YOURNAME_link
- make a CCK field_remote_YOURNAME_image

So the field ... _link is used to fill the field ... _image

Status of this module

Done:
- Get a remote file into Drupals File System
- Dirty attach this remote file from a CCK URL field to a CCK Image field

Roadmap for this module is
- Add providers for restricted links
- Administer link to licenses based on providers