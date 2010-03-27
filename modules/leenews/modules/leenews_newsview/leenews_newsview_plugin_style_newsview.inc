<?php
	class leenews_newsview_plugin_style_newsview extends views_plugin_style {
		function render() {
		    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
		      vpr('views_plugin_style_default: Missing row plugin');
		      return;
		    }

		    // Group the rows according to the grouping field, if specified.
		    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

		    // Render each group separately and concatenate.  Plugins may override this
		    // method if they wish some other way of handling grouping.
		    $output = '';
		    foreach ($sets as $title => $records) {
		      if ($this->uses_row_plugin()) {
		        $rows = array();
		        foreach ($records as $row_index => $row) {
		          $this->view->row_index = $row_index;
		          $rows[] = $this->row_plugin->render($row);
		        }
		      }
		      else {
				$rows = array();
		        foreach ($records as $row_index => $row) {
				  $afield = array();
				  foreach ($this->view->field as $id => $field) {
				  	$afield[$id] = $this->view->style_plugin->get_field($row_index, $id);
				  }		
				  $rows[] = $afield;
		        }	
		      }

		      $output .= theme($this->theme_functions(), $this->view, $this->options, $rows, $title);
		    }
		    unset($this->view->row_index);
		    return $output;
		  }
	}