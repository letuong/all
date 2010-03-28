<?php if ($rows): ?>
	<ul class="news-list">
		<?php
		 $first_news = 0;
		?>
		
		<?php foreach ($rows AS $row): ?>
			<li>
				<div><?php print $row['title']; ?></div>	
				<?php if ($first_news == 0): ?>
					<div class="clearfix news-summary">
						
						<?php 
						if (isset($row['field_news_thumbnail_fid'])) {
							print $row['field_news_thumbnail_fid'];
						} 
						?>
						<p>
							<?php print $row['teaser']; ?>
						</p>	
					</div>	
					<div class="news-other">Other News</div>
				<?php $first_news=1; endif; ?>
			</li>		
		<?php endforeach;?>
	</ul>
<?php endif; ?>